cmake_minimum_required(VERSION 3.12)
project(os_jit)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(os_jit main.cpp funcHandler.cpp funcHandler.h "divMe.h")