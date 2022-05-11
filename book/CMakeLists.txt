cmake_minimum_required(VERSION 3.20)
project(book)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(book
        main.cpp
        quote.h)
