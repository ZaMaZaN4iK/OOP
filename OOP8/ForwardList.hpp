//
// Created by zamazan4ik on 28.09.16.
//

#ifndef OOP6_FORWARDLIST_HPP
#define OOP6_FORWARDLIST_HPP

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

template <typename T>
class ForwardList
{
private:
    struct Node
    {
        T val;
        Node* next_node = nullptr;

        Node(T value, Node* node = nullptr) : val(value), next_node(node) {}

        bool operator!=(const Node& value) const
        {
            return val != value.val;
        }
    };

    Node* begin = nullptr;
    size_t size = 0;

public:
    ForwardList& operator+(T val)
    {
        if(val > 100500)    throw TooBigValue();
        if(val == 0)    throw ZeroValue();
        if(size == 0)
        {
            begin = new Node(val);
            ++size;
            return *this;
        }
        Node* ptr = begin;
        while(ptr->next_node != nullptr)
        {
            ptr = ptr->next_node;
        }
        ptr->next_node = new Node(val);
        ++size;
        return *this;
    }
    ForwardList& operator--(int)
    {
        if(size == 0)
        {
            throw MyException();
            //return *this;
        }
        if(size == 1)
        {
            delete begin;
            begin = nullptr;
            --size;
            return *this;
        }
        Node* ptr = begin;
        while(ptr->next_node && ptr->next_node->next_node)
        {
            ptr = ptr->next_node;
        }

        delete ptr->next_node;
        ptr->next_node = nullptr;
        --size;

        return *this;
    }
    T& operator[](size_t ind) const
    {
        if(ind >= size)
        {
            throw InvalidIndex();
        }
        Node* ptr = begin;
        for(size_t i = 0; i < ind; ++i)
        {
            ptr = ptr->next_node;
        }
        return ptr->val;
    }
    bool operator!=(const ForwardList& value)
    {
        if(size != value.size)    return false;
        for(size_t i = 0; i < size; ++i)
        {
            if(operator[](i) != value[i])
            {
                return false;
            }
        }
        return true;
    }

    size_t getSize() const
    {
        return size;
    }
};

#endif //OOP6_FORWARDLIST_HPP
