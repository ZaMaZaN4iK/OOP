//
// Created by zamazan4ik on 01.09.16.
//

//I use header-only class because class is too small and making for it class
//*.cpp is silly, IMHO.

#ifndef OOP2_TIME_HPP
#define OOP2_TIME_HPP

#include <iostream>

class Time
{
public:
    //Constructors
    Time()
    {
        std::cout << this <<" Default constructor" << std::endl;
    }

    Time(Time& time)
    {
        std::cout << this <<" Copy constructor" << std::endl;
        hour_ = time.hour_;
        minute_ = time.minute_;
        second_ = time.second_;
    }

    Time(size_t hour, size_t minute, size_t second) : hour_(hour), minute_(minute), second_(second)
    {
        std::cout << this <<" Constructor with parameters" << std::endl;
    }

    //Destructor
    ~Time()
    {
        std::cout << this <<" Destructor" << std::endl;
    }

    //Methods
    static size_t getObjectsCount()
    {
        return CountOfObjects;
    }

    //Setters
    void setHour(size_t hour)
    {
        if(hour < 24)
            hour_ = hour;
    }
    void setMinute(size_t minute)
    {
        if(minute < 60)
            minute_ = minute;
    }
    void setSecond(size_t second)
    {
        if(second < 60)
            second_ = second;
    }

    //Getters
    size_t getHour() const
    {
        return hour_;
    }
    size_t getMinute() const
    {
        return minute_;
    }
    size_t getSecond() const
    {
        return second_;
    }

    //Print
    void print() const
    {
        timeOfDay();
        std::cout << hour_ << ':' << minute_ << ':' << second_ << std::endl;
    }

    void formatPrint() const
    {
        timeOfDay();
        std::cout << hour_ << " hour " << minute_ << " minute " << second_ << " second" << std::endl;
    }
private:
    //Suggestion: We can call it e.g. inside a class
    Time(bool flag/*for overloading*/)//we can use for incrementing object's count
    {
        std::cout << this <<" Private constructor" << std::endl;
        ++CountOfObjects;
    }

    void timeOfDay() const
    {
        if(hour_ >= 0 && hour_ < 4) std::cout << "Night: ";
        else if(hour_ >= 4 && hour_ < 11 ) std::cout << "Morning: ";
        else if(hour_ >= 11 && hour_ < 17) std::cout << "Day: ";
        else std::cout << "Evening: ";
    }

    const size_t SecsInDay = 86400;
    static size_t CountOfObjects;
    size_t hour_, minute_, second_;
};

size_t Time::CountOfObjects = 0;

#endif //OOP2_TIME_HPP
