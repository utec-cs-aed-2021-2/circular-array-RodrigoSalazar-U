cmake_minimum_required(VERSION 3.20)
project(circular_array_RodrigoSalazar_U)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(circular_array_RodrigoSalazar_U
        circulararray.h
        main.cpp
        queue.h
        stack.h
        tester.h)
