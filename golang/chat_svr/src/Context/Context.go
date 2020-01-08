/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: Context.go
 * Author: ahaoozhang
 * Date: 2019-08-21 14:18:52 (星期三)
 * Describe: 
 *************************************************/
package Context

import (
	"chat_svr/proto/chatter"
	"github.com/golang/protobuf/proto"
	"log"
	"net"
	"reflect"
)

var RegisterMapper = make(map[uint32]register)

type handle func(*ChatterContext)

type ChatterContext struct {
	logger *log.Logger
	Cmd uint32

	//包含chatter包的所有内容
	Request *chatter.Request
	Response *chatter.Response

	//具体的业务请求
	ReqBody proto.Message
	RspBody proto.Message

	//客户端的Addr
	ClientAddr *net.UDPAddr
}

type register struct {
	reqType reflect.Type
	rspType reflect.Type
	h handle
}

// 返回空的ctx
func NewContext() *ChatterContext {
	return &ChatterContext {

	}
}

func RegisterFunc(cmd uint32, req proto.Message, rsp proto.Message, h handle) {
	RegisterMapper[cmd] = register{
		reqType: reflect.TypeOf(req),
		rspType: reflect.TypeOf(rsp),
		h:       h,
	}
}

func GetRegisterInfo(cmd uint32) (reflect.Type, reflect.Type, handle, error) {
	log.Println("Getregister Info, RegisterMap:", RegisterMapper)
	reqType := RegisterMapper[cmd].reqType
	rspType := RegisterMapper[cmd].rspType
	h := RegisterMapper[cmd].h
	log.Printf("reqType: %v, rspType: %v, h: %v", reqType, rspType, h)
	return reqType, rspType, h, nil
}

func (ctx *ChatterContext) Unmarshal(buff []byte) (handle, error) {
	//整体包的内容
	ctx.Request = &chatter.Request{}
	ctx.Response = &chatter.Response{}

	//解析chatter包内容
	_ = proto.Unmarshal(buff, ctx.Request)
	log.Printf("msg: %+v", ctx.Request)

	//解析chatter包之后设置cmd
	ctx.Cmd = ctx.Request.GetCmd()

	//根据cmd判断ex字段应该解析的类型 h为对应cmd的处理函数
	reqBodyType, rspBodyType, h, _ := GetRegisterInfo(ctx.Cmd)

	log.Println("req Type:", reqBodyType)
	log.Println("rsp Type:", rspBodyType)

	reqBody, _ := reflect.New(reqBodyType.Elem()).Interface().(proto.Message)
	rspBody, _ := reflect.New(rspBodyType.Elem()).Interface().(proto.Message)

	//解析ex字段信息
	_ = proto.Unmarshal(ctx.Request.GetEx(), reqBody)

	//讲解析好的reqbody设置进ctx
	ctx.ReqBody = reqBody
	ctx.RspBody = rspBody

	return h, nil
}

func (ctx *ChatterContext) Marshal() ([]byte, error) {
	//首先序列化自定义协议响应部分
	buff, _ := proto.Marshal(ctx.RspBody)
	ctx.Response.Ex = buff
	ctx.Response.Result = proto.Uint32(0)

	data, _ := proto.Marshal(ctx.Response)
	return data, nil
}


func XXX(ctx *ChatterContext){}


