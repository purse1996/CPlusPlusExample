cmake_minimum_required(VERSION 3.20)
project(string)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(string
        main.cpp
        myString.h)
