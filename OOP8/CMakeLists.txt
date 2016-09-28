cmake_minimum_required(VERSION 3.6)
project(OOP6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ForwardList.hpp Exceptions.hpp)
add_executable(OOP6 ${SOURCE_FILES})