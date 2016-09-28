//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Express.hpp"

Express::Express(const std::string& str, const double p,
        const double volumeEng, const double powerEng,
        const bool isTurbo, const std::vector<Carriage> car,
        const bool turboSpeed) :
        Train(str, p, volumeEng, powerEng, isTurbo, car), turboSpeed_(turboSpeed)
{
    std::cout << "Express constructor\n";
}

int Express::ExpressCount = 0;