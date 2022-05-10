cmake_minimum_required(VERSION 3.20)
project(smart_pointer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(smart_pointer
        main.cpp
        pointer.cpp
        pointer.h)
