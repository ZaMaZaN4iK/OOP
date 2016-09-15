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
    Carriage(){}
    Carriage(const std::string& str, const double v);

    void setSerial(const std::string& str) { serialNum = str; }
    void setVolume(const double maxVolume) { volume = maxVolume; }
};


#endif //OOP3_CARRIAGE_HPP
