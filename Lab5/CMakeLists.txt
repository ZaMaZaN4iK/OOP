cmake_minimum_required(VERSION 3.6)
project(OOP3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp jsoncpp.cpp Auto.hpp Auto.cpp Carriage.hpp Carriage.cpp Express.cpp Train.hpp Vehicle.hpp Express.hpp Train.cpp Vehicle.cpp AbstractVehicle.hpp SuperAbstractVehicle.hpp Printer.cpp Printer.hpp Container.cpp Container.hpp Controller.cpp Controller.hpp Inspector.cpp Inspector.hpp Curator.cpp Curator.hpp)
add_executable(OOP3 ${SOURCE_FILES})