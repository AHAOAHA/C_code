/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: default.go
 * Author: ahaoozhang
 * Date: 2019-07-03 09:50:37 (Wednesday)
 * Describe: 
 *************************************************/
package main

import (
	"fmt"
	"time"
)

func main() {
	ticker := time.NewTicker(time.Second)
	for {
		select {
		case <-ticker.C:
			fmt.Println("hello")
		default:

		}
	}
}
