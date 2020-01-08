/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: sliceCap.go
 * Author: ahaoozhang
 * Date: 2019-07-05 03:03:52 (Friday)
 * Describe: 
 *************************************************/
package main

import (
	"fmt"
	//"time"
)

func main() {
	//sli := make([]int, 0)
	//
	//for oldCap := cap(sli); oldCap < 100000; oldCap = cap(sli) {
	//	sli = append(sli, 1)
	//	newCap := cap(sli)
	//	if newCap != oldCap {
	//		fmt.Printf("cap: %d\n", cap(sli))
	//	}
	//	time.Sleep(time.Microsecond * 500)
	//}

    var sli []int
    sli =  append(sli, 0,1,2,3,4,5,6,7,8,9) 
    fmt.Println(sli[9:20])
}
