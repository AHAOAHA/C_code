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
	"fmt"
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
		fmt.Printf("name, word")
		var name string
		var word string
		fmt.Scanf("%s", &name)
        fmt.Scanf("%s", &word)
		ms := msg.Msg{
			Name: proto.String(name),
			Word: proto.String(word),
		}

		v, _ := proto.Marshal(&ms)

		listener.WriteToUDP(v, &net.UDPAddr{IP: net.ParseIP("104.248.159.192"), Port: 8000})

		log.Println("sendto: %+v", v)

		_, k, _ := listener.ReadFromUDP(data)
		log.Printf("serv IP: %s", k.String())
		m := &msg.Msg{}
		proto.Unmarshal(data, m)

		log.Printf("msg:[name: %s, word: %s]", m.GetName(), m.GetWord())

	}

}
