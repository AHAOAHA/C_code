package main

import (
	"fmt"
	"sync"
	"time"
)

func write1(ch chan string) {
	str := "hello world1"
	for {
		ch <- str
		time.Sleep(time.Second * 10)
	}
}

func write2(ch chan string) {
	str := "ahaoozhang"
	for {
		time.Sleep(time.Second * 5)
		ch <- str
		time.Sleep(time.Second)
	}
}

func write3(ch chan string) {
	str := "ahaoozhang ahaoozhang"
	for {
		ch <- str
		fmt.Println("no block")
	}
}

func testpool() {
	pool := sync.Pool{}
	h := pool.Get()
	if h == nil {
		fmt.Println("---------------------------")
	}
}

func main() {
	// ch := make(chan string, 1)
	// go write3(ch)
	// time.Sleep(time.Second * 5)
	// // go write1(ch)
	// // //go write2(ch)
	// for v := range ch {
	// 	fmt.Println(v)
	// 	//fmt.Println("no wait...")
	// }
	//testpool()
	buf := []int{}
	buf = append(buf, 1)
	buf = append(buf, 2)
	buf = append(buf, 3)
	fmt.Println(buf)

}
