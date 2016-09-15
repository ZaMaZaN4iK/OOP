//
// Created by zamazan4ik on 15.09.16.
//

#include "Controller.hpp"
#include "Container.hpp"

Controller::Controller(Container& container) : cont(container)
{
}

void Controller::sort()
{
    cont.sort();
}

double Controller::getAllCost()
{
    double result = 0.0;
    auto tempCont = cont.getArray();
    for(const auto ptr : tempCont)
    {
        result += ptr->getCost();
    }
    return result;
}

Vehicle* Controller::getSpeedVehicle(const double from, const double to)
{
    auto tempCont = cont.getArray();
    for(const auto ptr : tempCont)
    {
        double speed = ptr->getSpeed();
        if(speed >= from && speed <= to)//Dangerous compare
            return ptr;
    }
    return nullptr;
}