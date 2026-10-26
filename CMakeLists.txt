cmake_minimum_required(VERSION 3.0)
project(AutoVector)

set(CMAKE_CXX_STANDARD 20)

add_executable(AutoVector main.cpp
        main.cpp
        Buffer.h
        Buffer.tpp
        AutoVector.h
        AutoVector.tpp
)
