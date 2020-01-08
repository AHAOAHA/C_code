/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: slice.go
 * Author: ahaoozhang
 * Date: 2019-07-05 02:21:39 (Friday)
 * Describe: 
 *************************************************/
package main

func main() {
	s := make([]int, 3, 10)
	_ = f(s)
}

func f(s []int) int {
	return s[1]
}