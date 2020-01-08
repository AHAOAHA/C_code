/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: syscall.go
 * Author: ahaoozhang
 * Date: 2019-08-06 11:58:35 (星期二)
 * Describe:
 *************************************************/
package main

import (
	"demo43-syscall/shm"
	"fmt"
	"time"
	"unsafe"
)

const (
	IPC_CREATE = 00001000

	SUN_SHM_KEY = 0x5fee
)

func main() {
	//分配共享内存
	addr, _ := shm.GetShm(SUN_SHM_KEY, 4, 0666)
	fmt.Println("syscall1 addr:", addr)
	p := (*int)(unsafe.Pointer(addr))

	var count int = 0
	for {
		*p = count
		count = count + 1
		time.Sleep(time.Millisecond * 10)
	}
}
