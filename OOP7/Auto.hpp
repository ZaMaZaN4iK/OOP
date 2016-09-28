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
    Auto() {}
    Auto(const std::string& str, const double p,
         const double volumeEng, const double powerEng,
         const bool isTurbo, const bool isTO);

    void setTO(const bool isTO) { isTO_ = isTO;}

    virtual void toConsole()
    {
        std::cout << isTO_ << std::endl;
    }
};


#endif //OOP3_AUTO_HPP
