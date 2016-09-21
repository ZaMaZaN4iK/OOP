//
// Created by zamazan4ik on 21.09.16.
//

#ifndef OOP3_INSPECTOR_HPP
#define OOP3_INSPECTOR_HPP

#include <iostream>

#include "Express.hpp"

class Inspector
{
public:
    void IKnowAllAboutYou(Express express)
    {
        std::cout << express.turboSpeed_ << express.SomeMagicValue << std::endl;
    }
};


#endif //OOP3_INSPECTOR_HPP
