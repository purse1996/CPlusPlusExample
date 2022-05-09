cmake_minimum_required(VERSION 3.20)
project(fraction)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fraction
        fraction.h
        main.cpp)
