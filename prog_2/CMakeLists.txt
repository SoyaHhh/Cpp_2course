cmake_minimum_required(VERSION 3.20)
project(prog_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(prog_2 main.cpp RingBuffer.cpp RingBuffer.h Iterator.cpp Iterator.h)
