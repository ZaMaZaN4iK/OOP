#include <iostream>
#include <vector>
#include "Time.hpp"

int main()
{
    Time a, d;
    Time b(1,2,3);
    Time c(b);
    Time* ptrD = new Time;
    delete ptrD;
    Time arr[5];
    for(size_t i = 0;i < 5; ++i)
    {
        arr[i].setHour(i);
        arr[i].setMinute(i);
        arr[i].setSecond(i);
    }
    for(const auto& val : arr)
    {
        if(val.getHour() == 4)
        {
            std::cout << "FOUND! :" << std::endl;
            val.print();
            val.formatPrint();
            std::cout << std::endl;
        }
        else
            val.print();
    }
    return 0;
}

