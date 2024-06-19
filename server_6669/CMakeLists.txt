cmake_minimum_required(VERSION 3.28)
project(tcp_th_srv)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(tcp_th_srv main.cpp
        serv_80.cpp
        serv_80.h)
target_link_libraries(tcp_th_srv Threads::Threads)