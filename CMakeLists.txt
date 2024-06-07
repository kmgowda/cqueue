cmake_minimum_required(VERSION 3.27)
project(cqueue CXX)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(benchmark REQUIRED)
find_package(boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set( sources main.cpp queuebenchmark.cpp
        QueueInterface.h)

add_executable(cqueue ${sources})

#target_link_libraries(cqueue benchmark::benchmark ${Boost_LIBRARIES})

target_link_libraries(cqueue benchmark::benchmark Boost::boost)