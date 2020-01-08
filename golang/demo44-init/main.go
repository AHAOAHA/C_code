/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: main.go
 * Author: ahaoozhang
 * Date: 2019-08-12 15:56:25 (星期一)
 * Describe:
 *************************************************/
package main

import (
	_ "demo44-init/package1"
    _ "demo44-init/package2"
	"fmt"
)

func init() {
	fmt.Println("xxxxxxxxxxxxxxx")
}

func main() {

}
