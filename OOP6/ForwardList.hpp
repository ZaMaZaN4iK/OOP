//
// Created by zamazan4ik on 28.09.16.
//

#ifndef OOP6_FORWARDLIST_HPP
#define OOP6_FORWARDLIST_HPP

/*Класс однонаправленный список List. Дополнительно перегрузить следующие
        операции: + добавить элемент в конец (list+item); --удалить элемент из конца (типа list--);
!= проверка на неравенство; [] - доступ к элементу в заданной позиции.*/

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
            return *this;
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
};

#endif //OOP6_FORWARDLIST_HPP
