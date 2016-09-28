//
// Created by zamazan4ik on 28.09.16.
//

#ifndef OOP6_EXCEPTIONS_HPP
#define OOP6_EXCEPTIONS_HPP

#include <exception>

struct MyException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "My exception";
    }
};

struct InvalidIndex : public MyException
{
    virtual const char* what() const throw()
    {
        return "Invalid index";
    }
};

struct ZeroValue : public MyException
{
    virtual const char* what() const throw()
    {
        return "Zero value";
    }
};

struct TooBigValue : public MyException
{
    virtual const char* what() const throw()
    {
        return "TooBigValue";
    }
};

#endif //OOP6_EXCEPTIONS_HPP
