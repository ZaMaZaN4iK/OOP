//
// Created by zamazan4ik on 15.09.16.
//

#ifndef OOP3_ABSTRACTVEHICLE_HPP
#define OOP3_ABSTRACTVEHICLE_HPP

#include "SuperAbstractVehicle.hpp"

class AbstractVehicle : protected SuperAbstractVehicle
{
private:
    virtual void checkNestedClass() = 0;
public:
    virtual void toConsole() = 0;
};

#endif //OOP3_ABSTRACTVEHICLE_HPP
