CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(test)

# default off
OPTION(DEFINE_HELLO_WORLD "Option description" OFF)

if(DEFINE_HELLO_WORLD)
add_definitions(-DHELLO_WORLD)
endif(DEFINE_HELLO_WORLD)

add_executable(test test.cpp)
