cmake_minimum_required(VERSION 3.20)
project(functor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(functor
        bigger.h
        main.cpp)
