/******************************************************************
 * Copyright(C) 2016-2020. All right reserved.
 * 
 * Filename: main.cpp
 * Author: ahaoozhang
 * Date: 2020-01-18 13:08:13 (Saturday)
 * Describe: grpc demo, return string hello world.
 ******************************************************************/
#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "demogrpc.pb.h"
#include "demogrpc.grpc.pb.h"

using namespace std;
using namespace grpc;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using namespace DemoGrpc;

// 未生成DemoGrpc::Service

class DemoServiceImpl final : public DemoGrpcer::Service {
    Status GetDemoRsp(ServerContext* context, const DemoReq* req, DemoRsp* rsp) override {
        rsp->set_rsp("this is rsp");
        return Status::OK;
    }
};
 

void RunServer() {
    std::string server_address("0.0.0.0:8080");
    DemoServiceImpl service;
    
    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    
    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}
 
int main(int argc, char** argv) {
  RunServer();
 
  return 0;
}

