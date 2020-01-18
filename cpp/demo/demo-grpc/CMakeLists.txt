cmake_minimum_required(VERSION 2.8)

project(DemoGrpc)

set(CMAKE_CXX_FLAGS "-std=c++11")

aux_source_directory(./src SRC)
aux_source_directory(./grpc SRC_GRPC)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/grpc)

include_directories(${CMAKE_SOURCE_DIR}/third-party/protobuf/include)
include_directories(${CMAKE_SOURCE_DIR}/third-party/grpc/include)

link_directories(${CMAKE_SOURCE_DIR}/third-party/protobuf/lib)
link_directories(${CMAKE_SOURCE_DIR}/third-party/grpc/lib)

set(THIRD_LIB libprotobuf.a pthread libgrpc++.a libgrpc.a libgpr.a libaddress_sorting.a libcares.a libz.a)

add_executable(DemoGrpc ${SRC} ${SRC_GRPC})
target_link_libraries(DemoGrpc ${THIRD_LIB})

