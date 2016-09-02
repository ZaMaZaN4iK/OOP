//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_EXPRESS_HPP
#define OOP3_EXPRESS_HPP

#include "Train.hpp"

class Express : public Train
{
private:
    bool turboSpeed_;
public:
    Express(const std::string& str, const double p,
            const double volumeEng, const double powerEng,
            const bool isTurbo, const std::vector<Carriage> car,
            const bool turboSpeed);
};


#endif //OOP3_EXPRESS_HPP
