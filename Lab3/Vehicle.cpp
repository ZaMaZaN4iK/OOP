//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Vehicle.hpp"

Vehicle::Vehicle(const double volumeEng, const double powerEng,
                 const bool isTurbo, const std::string &str,
                 const double abstractSize) : engine_(Engine(volumeEng, powerEng, isTurbo)),
                                       serialNum(str), size(abstractSize)
{
    std::cout << "Vehicle constructor\n";
}