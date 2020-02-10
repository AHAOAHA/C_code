/******************************************************************
 * Copyright(C) 2020-2020. All right reserved.
 * 
 * Filename: future.cpp
 * Author: ahaoozhang
 * Date: 2020-02-10 13:53:36 (Monday)
 * Describe: std::promise & std::future 功能类似于golang的sync.WaitGroup 
 * 是一个用来异步控制的工具
 ******************************************************************/
#include <future>
#include <iostream>
#include <thread>
#include <memory>
#include <unistd.h>

using namespace std;

void wait_for(std::promise<bool> promise) {
    sleep(5);
    promise.set_value(true);
    while(1) {
        sleep(1);
    }
}

int main() {
    std::promise<bool> promise;
    auto future = promise.get_future();
    // set_promise运行结束之后wait_for再开始运行
    unique_ptr<thread> th1(new thread(&wait_for, std::move(promise)));
    if(future.get()){
        cout << "done!" << endl;
    }
    th1->join();
    return 0;
}
