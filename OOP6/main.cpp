#include <iostream>

#include "ForwardList.hpp"

/*Класс однонаправленный список List. Дополнительно перегрузить следующие
        операции: + добавить элемент в конец (list+item); --удалить элемент из конца (типа list--);
!= проверка на неравенство; [] -доступ к элементу в заданной позиции.*/

int main()
{
    ForwardList<int> list1, list2;
    list1+5;
    std::cout << (list1 != list2) << std::endl;
    std::cout << list1[0] << std::endl;
    list1--;
    std::cout << (list1 != list2) << std::endl;
    return 0;
}