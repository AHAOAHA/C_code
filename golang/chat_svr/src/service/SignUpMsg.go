/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 *
 * Filename: RegistedMsg.go
 * Author: ahaoozhang
 * Date: 2019-08-20 19:52:40 (星期二)
 * Describe: 注册逻辑
 *************************************************/
package service

import (
	"chat_svr/Context"
	"chat_svr/proto/basic_svr"
	"log"
	"net"
)

type ClientUserInfo struct {
	Id      uint64
	Nick    string
	CliAddr *net.UDPAddr
}

var Mapper = make(map[uint64]ClientUserInfo)

//用户注册，内存注册
func SignUpMsg(ctx *Context.ChatterContext) {
	req := ctx.ReqBody.(*basic_svr.SignUpReq)
	log.Println("req:", req)
	id := req.GetUserInfo().GetId()
	nick := req.GetUserInfo().GetNick()

	_, ok := Mapper[id]
	log.Printf("Id: %d, Mapper: %+v, ok: %v", id, Mapper, ok)
	if ok {
		log.Println("[ERROR] id already exist!")
		return
	}

	log.Printf("ID: %d, Nick: %s", id, nick)

	Mapper[id] = ClientUserInfo{
		Id:      id,
		Nick:    nick,
		CliAddr: ctx.ClientAddr,
	}

	log.Printf("SignUp Success, Curr Maspper: %+v", Mapper)

}
