cmake_minimum_required(VERSION 3.20)
project(complex)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(complex
        complex.h
        main.cpp)
