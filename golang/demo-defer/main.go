package main

import (
	"fmt"
)

// 跟在return后面的返回值在执行的defer之前会被拷贝一份
// copy return back obj'
// run defer(obj)
// return obj

func Func1() int {
	r := 1
	defer func() {
		r = 2
	}()

	return r
}


// no copy
// run defer
// return obj
func Func2() (r int) {
    r = 1
    defer func() {
        r = 2
    }()
    return
}

func main() {
	fmt.Println("r1:", Func1())
	fmt.Println("r2:", Func2())
}

// r:1

