/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: shm.go
 * Author: ahaoozhang
 * Date: 2019-08-06 14:46:05 (星期二)
 * Describe: 通过key值获取共享内存
 *************************************************/
package shm

import "syscall"
import "fmt"

const IPC_CREATE = 00001000

func GetShm(key int, size int, shmFlag int) (uintptr, error) {
	id, _, errno := syscall.Syscall(syscall.SYS_SHMGET, /*指明用来创建共享内存*/
		uintptr(int32(key)),     /*指明创建共享内存的key值*/
		uintptr(int32(size)),    /*指明共享内存的大小 单位字节*/
		uintptr(int32(IPC_CREATE | shmFlag))) /*指明共享内存的属性*/

    fmt.Println("sdm id:", int32(id))
	if int(id) < 0 {
		return 0, errno
	}

	addr, _, errno := syscall.Syscall(syscall.SYS_SHMAT, /*指明将共享内存映射进虚拟地址空间*/
		uintptr(int32(id)), /*要进行映射的共享内存ID*/
		0,                  /*未知*/
		0)                  /*未知*/

    fmt.Println("shm addr", int(addr))
	if int(addr) < 0 {
		return 0, errno
	}

	return addr, nil
}
