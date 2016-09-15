//
// Created by zamazan4ik on 15.09.16.
//

#include <algorithm>

#include "Container.hpp"


void Container::push_back(Vehicle* value)
{
    array.push_back(value);
}

void Container::pop_back()
{
    array.pop_back();
}

void Container::sort()
{
    std::sort(array.begin(), array.end(), [](const Vehicle* val1, const Vehicle* val2) -> bool
            { return *val1 < *val2;});
}

void Container::print()
{
    for(const auto ptr : array)
    {
        ptr->toConsole();
    }
}