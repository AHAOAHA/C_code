/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: main.go
 * Author: ahaoozhang
 * Date: 2019-08-20 19:24:57 (星期二)
 * Describe:
 *************************************************/
package main

import (
	"chat_svr/Context"
	"chat_svr/proto/basic_svr"
	"chat_svr/service"
	"log"
	"net"
)



func init() {
	//服务开始之前将对应命令的处理函数以及结构体注册
	Context.RegisterFunc(0x1, &basic_svr.SignUpReq{}, &basic_svr.SignUpRsp{}, service.SignUpMsg)
	Context.RegisterFunc(0x3, &basic_svr.GetOnlineUserListReq{}, &basic_svr.GetOnlineUserListRsp{}, Context.XXX)
	Context.RegisterFunc(0x4, &basic_svr.SendMsgReq{}, &basic_svr.SendMsgRsp{}, Context.XXX)
}



func main() {
	// udp listener
	log.Println("serv run")
	listener, _ := net.ListenUDP("udp", &net.UDPAddr{IP: net.ParseIP("0.0.0.0"), Port: 8000})
	buff := make([]byte, 64*1024)
	for {
		_, cliaddr, _ := listener.ReadFromUDP(buff)
		log.Printf("cliaddr: %s", cliaddr.String())

		ctx := Context.NewContext()

		//设置客户端IP地址
		ctx.ClientAddr = cliaddr

		//pb反序列化 ctx中包含请求 响应所有信息
		h, _ := ctx.Unmarshal(buff)

		//处理请求，完成之后会将响应写入ctx包中
		h(ctx)

		//pb序列化
		data, _ := ctx.Marshal()

		 _, _ = listener.WriteToUDP(data, cliaddr)
	}
}
