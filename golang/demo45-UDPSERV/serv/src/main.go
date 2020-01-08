/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: main.go
 * Author: ahaoozhang
 * Date: 2019-08-20 16:17:33 (星期二)
 * Describe:
 *************************************************/
package main

import (
	"log"

	"net"
	"serv/msg"

	"github.com/golang/protobuf/proto"
)

func main() {

	listener, _ := net.ListenUDP("udp", &net.UDPAddr{
		IP:   net.ParseIP("0.0.0.0"),
		Port: 8000,
	})

	log.Printf("listening 8000\n")

	data := make([]byte, 64*1024)

	for {
		_, cnet, _ := listener.ReadFromUDP(data)
		log.Println("client IP: %s", cnet.String())

		ms := &msg.Msg{}
		_ = proto.Unmarshal(data, ms)
		log.Printf("msg:[name: %s, word: %s]", ms.GetName(), ms.GetWord())

		m := msg.Msg{
			Name: proto.String("ok"),
			Word: proto.String("OK"),
		}

		buff, _ := proto.Marshal(&m)
		listener.WriteToUDP(buff, cnet)
	}

}
