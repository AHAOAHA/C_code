/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: rangeChan.go
 * Author: ahaoozhang
 * Date: 2019-07-04 02:10:20 (星期四)
 * Describe: 使用for+range对chan进行遍历的效果
 *************************************************/
package main

import (
	"fmt"
	"time"
	"strconv"
)

func main() {
	ch := make(chan string, 1024)

	go func(in *chan string) {
		for count := 10; count != 0; count-- {
			ch<-("hello world "+strconv.Itoa(count))
			time.Sleep(time.Millisecond * 500)
		}

		close(ch)
	}(&ch)

	go func(out *chan string) {
		for h := range *out {
			fmt.Println(h)
		}

		fmt.Println("range over ...")
	}(&ch)

	time.Sleep(time.Second * 100)
}
