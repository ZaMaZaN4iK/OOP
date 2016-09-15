//
// Created by zamazan4ik on 15.09.16.
//

#ifndef OOP3_PRINTER_HPP
#define OOP3_PRINTER_HPP

#include <iostream>
#include <typeinfo>

#include "AbstractVehicle.hpp"

class Printer
{
public:
    void iAmPrinting(AbstractVehicle* obj)
    {
        std::cout << typeid(*obj).name() << std::endl;
        obj->toConsole();
    }
};


#endif //OOP3_PRINTER_HPP
