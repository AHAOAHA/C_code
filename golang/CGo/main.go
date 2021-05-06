package main

/*
struct A {
    int x;
    char arc[10];
    int ari[10];
};
void f(struct A* stu) {
    stu->x = 10;
    int i = 0;
    for (i = 0; i < 10; i++) {
        stu->arc[i] = 'x';
    }
    for (i = 0; i < 10; i++) {
        stu->ari[i] = 9;
    }
}
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

func main() {
	var x A
	ss := (*C.struct_A)(unsafe.Pointer(&x))
	C.f(ss)
	fmt.Printf("%+v\n", x)
}
