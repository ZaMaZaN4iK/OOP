//
// Created by zamazan4ik on 15.09.16.
//

#ifndef OOP3_CONTROLLER_HPP
#define OOP3_CONTROLLER_HPP

#include "Container.hpp"

class Controller
{
    Container& cont;
public:
    Controller(Container& container);

    void setContainer(Container& container) { cont = container; }

    void sort();
    double getAllCost();
    Vehicle* getSpeedVehicle(const double from, const double to);

    double magicMethodForExpress();
};


#endif //OOP3_CONTROLLER_HPP
