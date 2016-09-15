//
// Created by zamazan4ik on 15.09.16.
//

#ifndef OOP3_CONTAINER_HPP
#define OOP3_CONTAINER_HPP

#include <vector>

#include "Vehicle.hpp"

//Container is intrusive container. It's very rare, but very effective type of containers
//We don't store copies of objects - we store pointers to objects. And user work with it as with objects
//We avoid copying and memory allocating. But user should guarantee that lifetime of original objects >=
//intrusive container's lifetime.

class Container
{
private:
    std::vector<Vehicle*> array;
public:
    Container() = default;

    std::vector<Vehicle*> getArray() const { return array; }
    void setArray(std::vector<Vehicle*> arr) { array = arr; }

    void push_back(Vehicle* value);
    void pop_back();

    void sort();

    void print();
};


#endif //OOP3_CONTAINER_HPP
