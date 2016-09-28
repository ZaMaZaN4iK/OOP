//
// Created by zamazan4ik on 15.09.16.
//

#include <typeinfo>

#include "Controller.hpp"
#include "Container.hpp"
#include "Express.hpp"

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

double Controller::magicMethodForExpress()
{

    auto temp = Express();
    auto range = cont.getArray();
    for(auto val : range)
    {
        std::cout << typeid(dynamic_cast<Express*>(val)).name() << " - " << typeid(&temp).name() << std::endl;
        if(dynamic_cast<Express*>(val) != nullptr &&
                typeid(dynamic_cast<Express*>(val)).name() == typeid(&temp).name())
        {
            std::cout << dynamic_cast<Express*>(val)->getTurboSpeed() << std::endl;
        }
    }
}