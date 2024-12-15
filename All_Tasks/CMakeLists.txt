
cmake_minimum_required(VERSION 3.10)
project(LR8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,leak -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address,undefined,leak")


set(CMAKE_CXX_COMPILER "g++")

add_executable(LR8
        LR8.cpp
        func_task1.cpp
        func_task2.cpp
        functions_1.h
        functions_2.h
)
