#include <iostream>
#include <assert.h>

#include "ForwardList.hpp"
#include "Express.hpp"
#include "Exceptions.hpp"

/*Модифицировать проект, созданный в предыдущем практикуме No7. Создать  иерархию  классов
исключений(собственных).Сделать наследование  пользовательских  типов  исключений
        от  иерархиикласса exception.Сгенерировать  и  обработать    как  минимум  пять
различных исключительных ситуаций. Например, не позволять при инициализации объектов передавать
неверные данные, обрабатывать ошибкипри работе с памятьюи ошибки работы с файлами, деление на ноль,
        неверный индекс, нулевой указатель и т. д.Обработку  исключений  вынести  в main.При  обработке
выводить специфическую информацию о месте и причине исключения. Последним должен быть блок, который
отлавливает все исключения.Добавьте код одной из функций максрос accert. Объясните что он проверяет,
        как будет выполняться программав случае не выполнения условия. Объясните назначение accert.
Что произойдет при определении NDEBUG*/

template<typename T>
void foo(ForwardList<T>& list)
{
    assert(list.getSize() != 0);
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

    //Lab7 and Lab8
    try
    {
        ForwardList<int> one;
        one + 6;
        ForwardList<double> two;
        two + 2.0;
        ForwardList<Express> three;
        foo<int>(one);
        foo<double>(two);
        foo<Express>(three);
    }
    catch(InvalidIndex& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    catch(ZeroValue& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    catch(TooBigValue& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    catch(MyException& myexp)
    {
        std::cout << myexp.what() << std::endl;
    }
    catch(std::bad_alloc& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Something interesting\n";
    }
    //Lab 8


    return 0;
}