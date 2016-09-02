//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_CARRIAGE_HPP
#define OOP3_CARRIAGE_HPP

#include <string>

class Carriage
{
private:
    std::string serialNum;
    double volume;
public:
    Carriage(const std::string& str, const double v);
};


#endif //OOP3_CARRIAGE_HPP
