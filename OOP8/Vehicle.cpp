//
// Created by zamazan4ik on 08.09.16.
//
#include <iostream>

#include "Vehicle.hpp"

Vehicle::Engine::Engine(const double volumeEng, const double powerEng, const bool isTurbo)
        : volume_(volumeEng), power_(powerEng), isTurbo_(isTurbo)
{
}

Vehicle::Vehicle(const double volumeEng, const double powerEng,
        const bool isTurbo, const std::string& str,
        const double abstractSize) : engine_(Engine(volumeEng, powerEng, isTurbo)), serialNum(str)
{

}

void Vehicle::meCanCallNestedClass()
{
    std::cout << "Hello, nested class" << std::endl;
}

void Vehicle::checkNestedClass()
{
    std::cout << engine_.onlyForParent << std::endl;
}