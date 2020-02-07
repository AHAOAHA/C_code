/******************************************************************
 * Copyright(C) 2020-2020. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2020-02-06 18:25:14 (Thursday)
 * Describe: 
 ******************************************************************/
#include <iostream>

int main() {
#ifdef HELLO_WORLD
    std::cout << "hello world!" << std::endl;
#endif
    return 0;
}
