//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_VEHICLE_HPP
#define OOP3_VEHICLE_HPP

#include <string>

#include "Engine.hpp"

class Vehicle
{
private:
    std::string serialNum;
    double size;
    Engine engine_;
public:
    Vehicle(const double volumeEng, const double powerEng,
            const bool isTurbo, const std::string& str,
            const double abstractSize);
};


#endif //OOP3_VEHICLE_HPP
