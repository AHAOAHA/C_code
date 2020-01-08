/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: syscall3.go
 * Author: ahaoozhang
 * Date: 2019-08-07 10:52:36 (星期三)
 * Describe: 
 *************************************************/
package main

import (
    "fmt"
    "os"
)

func main() {
    fmt.Println(os.Getpid())
}
