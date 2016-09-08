//
// Created by zamazan4ik on 02.09.16.
//
#include <iostream>

#include "Carriage.hpp"

Carriage::Carriage(const std::string& str, const double v) : serialNum(str), volume(v)
{
    std::cout << "Carriage constructor\n";
}