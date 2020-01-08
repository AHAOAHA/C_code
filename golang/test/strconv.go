/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: strconv.go
 * Author: ahaoozhang
 * Date: 2019-07-25 19:39:15 (星期四)
 * Describe: 
 *************************************************/
package main

import (
    "fmt"
)
func main() {
    //str := "1125000318"
    //fmt.Println(strconv.ParseInt(str));
    res := &struct{
         succ bool
         balance uint64
     }{}

    fmt.Printf("%+v", res)

}
