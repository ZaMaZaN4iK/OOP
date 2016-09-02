//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Engine.hpp"


Engine::Engine(const double volumeEng, const double powerEng, const bool isTurbo)
                    : volume_(volumeEng), power_(powerEng), isTurbo_(isTurbo)
{
    std::cout << "Engine constructor\n";
}