cmake_minimum_required(VERSION 3.20)
project(prog_03)

set(CMAKE_CXX_STANDARD 20)

add_executable(prog_03 main.cpp IList.h Iterator.h LinkedList.cpp LinkedList.h )
