package main

/*
#include "t.h"
*/
import "C"

import (
	"fmt"
	"unsafe"
)

type A struct {
	x    int32
	arrc [10]byte
	arri [10]int32
}

func GoStuInCFunc() {
	var x A
	ss := (*C.struct_A)(unsafe.Pointer(&x))
	C.f(ss)
	fmt.Printf("%+v\n", x)
}

//export export_in_Go
func export_in_Go() {
	fmt.Print("this is in Go\n")
}

func main() {
	// Go 调用 C传入传出函数
	GoStuInCFunc()

	// 执行C函数，C定义在Go
	C.export_in_Go()
}
