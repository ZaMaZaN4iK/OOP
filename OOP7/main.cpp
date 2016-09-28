#include <iostream>

#include "ForwardList.hpp"
#include "Express.hpp"


template<typename T>
void foo(ForwardList<T>& list)
{
    for(size_t i = 0; i < list.getSize(); ++i)
    {
        list[i] = list[i] * 2;
    }
}

int main()
{
    //Lab6
    ForwardList<int> list1, list2;
    list1+5;
    std::cout << (list1 != list2) << std::endl;
    std::cout << list1[0] << std::endl;
    list1--;
    std::cout << (list1 != list2) << std::endl;

    //Lab7
    ForwardList<int> one;
    one + 6;
    ForwardList<double> two;
    two + 2.0;
    ForwardList<Express> three;
    foo<int>(one);
    foo<double>(two);
    foo<Express>(three);

    return 0;
}