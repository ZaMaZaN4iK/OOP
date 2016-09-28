//
// Created by zamazan4ik on 08.09.16.
//

#ifndef OOP3_EXPRESS_HPP
#define OOP3_EXPRESS_HPP

#include <iostream>

#include "Train.hpp"

class Express;

class Curator
{
public:
    void iCanModify(Express& express);
};

class Express : public Train
{
    friend class Inspector;
    friend void Curator::iCanModify(Express& express);
private:
    bool turboSpeed_;
    const int SomeMagicValue = 42;
public:
    static int ExpressCount;

    Express(){ ++ExpressCount; }

    Express(const std::string& str, const double p,
                     const double volumeEng, const double powerEng,
                     const bool isTurbo, const std::vector<Carriage> car,
                     const bool turboSpeed);

    ~Express() { --ExpressCount; }

    void setTurboSpeed(const bool turboSpeed) { turboSpeed_ = turboSpeed; }

    bool getTurboSpeed() const { return turboSpeed_; }

    void printSomeMagicValue() const { std::cout << SomeMagicValue << std::endl; }

    virtual void toConsole()
    {
        std::cout << turboSpeed_ << std::endl;
    }

    Express& operator*(int val)
    {
        turboSpeed_ *= val;
        return *this;
    }

    Express& operator=(const Express& val)
    {
        if(&val == this)    return *this;
        *this = val;
        return *this;
    }

    static void printObjectsCount() { std::cout << ExpressCount << std::endl; }
};


#endif //OOP3_EXPRESS_HPP
