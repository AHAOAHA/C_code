/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.go
 * Author: ahaoozhang
 * Date: 2019-08-21 15:03:38 (星期三)
 * Describe: 
 *************************************************/
package main

import (
	"fmt"
	"github.com/golang/protobuf/proto"
	"chat_client/proto/chat_client"
	"net"
	"time"
)

const ServAddr = "104.248.159.192"
const ServPort = 8000

func main() {
	//用户登录, 注册
	fmt.Println("you should sign up first, please input some information")
	time.Sleep(time.Second)
	fmt.Printf("input ID:")
	var ID uint64
	_, _ = fmt.Scanf("%d", &ID)
	fmt.Printf("input NickName:")
	var Nick string
	_, _ = fmt.Scanf("%s", &Nick)

	UserInfo := chat_client.UserInfo{
		Id: proto.Uint64(ID),
		Nick: proto.String(Nick),
	}

	listener, _ := net.ListenUDP("udp", &net.UDPAddr{IP: net.ParseIP("0.0.0.0"), Port: 8000})

	sp_req := chat_client.SignInReq{
		UserInfo:             &UserInfo,
	}

	buff := make([]byte, 64 * 1024)

	buff, _ = proto.Marshal(&sp_req)

	ct_req := chat_client.ChatMsgReq{
		Cmd:                  proto.Uint32(1),
		Ex:                   buff,
	}

	ct_buff := make([]byte, 64 * 1024)
	ct_buff, _ = proto.Marshal(&ct_req)

	_, _ = listener.WriteToUDP(ct_buff, &net.UDPAddr{IP: net.ParseIP(ServAddr), Port: ServPort})

}
