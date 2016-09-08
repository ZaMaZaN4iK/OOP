//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Auto.hpp"

Auto::Auto(const std::string& str, const double p,
           const double volumeEng, const double powerEng,
           const bool isTurbo, const bool isTO) :
            Vehicle(volumeEng, powerEng, isTurbo, str, p), isTO_(isTO)
{
    std::cout << "Auto constructor\n";
}