//
// Created by zamazan4ik on 08.09.16.
//

#ifndef OOP3_EXPRESS_HPP
#define OOP3_EXPRESS_HPP

#include "Train.hpp"

class Express : public Train
{
private:
    bool turboSpeed_;
public:
    Express(){}

    Express(const std::string& str, const double p,
                     const double volumeEng, const double powerEng,
                     const bool isTurbo, const std::vector<Carriage> car,
                     const bool turboSpeed);

    void setTurboSpeed(const bool turboSpeed) { turboSpeed_ = turboSpeed; }
};

/*Express::Express(const std::string& str, const double p,
                 const double volumeEng, const double powerEng,
                 const bool isTurbo, const std::vector<Carriage> car,
                 const bool turboSpeed) :
        Train(str, p, volumeEng, powerEng, isTurbo, car), turboSpeed_(turboSpeed)
{
    std::cout << "Express constructor\n";
}*/

#endif //OOP3_EXPRESS_HPP
