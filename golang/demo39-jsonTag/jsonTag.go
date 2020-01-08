/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: jsonTag.go
 * Author: ahaoozhang
 * Date: 2019-07-03 03:08:21 (星期三)
 * Describe: json Tag的作用可以看作在编解码时格式化json字符串的key:value形式
 *************************************************/
// json Tag 第一个变量标识json的Key名 第二个变量标识选项 使用,分隔
package main

import (
	"fmt"
	//"encoding/json"
	//"reflect"
)

type Student struct {
	Name string `json:"-" xml:"NAME"`
	Age int32 `json:"age" xml:"AGE"`
	Class string
	Ptr uintptr `json:"ptr,omitempty"`
	Num int32 `json:"num,string"`
}

type dft struct {
    Num uint64 `default:"10000"`
}

func main() {
	//stu := Student {
	//	Name: "ahaoozhang",
	//	Age: 18,
	//	Class: "电信1605班",
	//	Num: 2000,
	//}

	////将上面的结构体转换为json格式并打印
	//json, _ := json.Marshal(stu)

	//fmt.Println(string(json))

	//stutype := reflect.TypeOf(stu)
	//for i := 0; i < stutype.NumField(); i++ {
	//	field := stutype.Field(i)
	//	fmt.Printf("json: %v; xml: %v\n", field.Tag.Get("json"), field.Tag.Get("xml"))
	//}
    var d dft
    fmt.Println(d.Num)
}
