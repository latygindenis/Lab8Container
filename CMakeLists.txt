cmake_minimum_required(VERSION 3.8)
project(Lab8Container)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp books.cpp books.h)
add_executable(Lab8Container ${SOURCE_FILES})