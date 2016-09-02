//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Train.hpp"

Train::Train(const std::string& str, const double p,
      const double volumeEng, const double powerEng,
      const bool isTurbo, const std::vector<Carriage> car)
        :   Vehicle(volumeEng, powerEng, isTurbo, str, p), carriages(car)
{
    std::cout << "Train constructor\n";
}