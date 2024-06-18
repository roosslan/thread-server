cmake_minimum_required(VERSION 3.28)
project(clnt80)

set(CMAKE_CXX_STANDARD 17)

add_executable(clnt80 main.cpp
        clnt_80.h
        clnt_80.cpp)
