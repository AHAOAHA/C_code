/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: syscall2.go
 * Author: ahaoozhang
 * Date: 2019-08-06 14:28:37 (星期二)
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

	SUM_SHM_KEY = 0x5fee
)

func main() {
	//讲共享内存转换为地址 size 4
	addr, _ := shm.GetShm(SUM_SHM_KEY, 4, 0666)
	fmt.Println("syscall2 addr:", addr)
	p := (*int)(unsafe.Pointer(addr))
	for {
		fmt.Println(*p)
		time.Sleep(time.Millisecond * 500)
	}

}
