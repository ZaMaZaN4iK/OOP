//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_AUTO_HPP
#define OOP3_AUTO_HPP

#include "Vehicle.hpp"

class Auto : public Vehicle
{
private:
    bool isTO_;
public:
    Auto(const std::string& str, const double p,
         const double volumeEng, const double powerEng,
         const bool isTurbo, const bool isTO);
};


#endif //OOP3_AUTO_HPP
