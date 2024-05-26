cmake_minimum_required(VERSION 3.27)
project(cqueue CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

set( sources cqueue.cpp)

add_executable(cqueue ${sources})
