#include <iostream>
#include <atomic>
#include <thread>
#include <unistd.h>

std::atomic<uint64_t> Count(0);

void ThreadAdd() {
    Count++;
    std::cout << "当前线程数：" << Count << std::endl;
    sleep(60 * 60);
}

int main() {
    while(true) {
        std::thread th(&ThreadAdd);
        th.detach();
        usleep(10);
    }
    return 0;
}