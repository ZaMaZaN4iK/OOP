//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_ENGINE_HPP
#define OOP3_ENGINE_HPP


class Engine
{
private:
    bool isTurbo_;
    double volume_, power_;
public:
    Engine(const double volumeEng, const double powerEng, const bool isTurbo);
};


#endif //OOP3_ENGINE_HPP
