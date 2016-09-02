//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_TRAIN_HPP
#define OOP3_TRAIN_HPP

#include <vector>

#include "Vehicle.hpp"
#include "Carriage.hpp"

class Train : public Vehicle
{
private:
    std::vector<Carriage> carriages;
public:
    Train(const std::string& str, const double p,
          const double volumeEng, const double powerEng,
          const bool isTurbo, const std::vector<Carriage> car);
};


#endif //OOP3_TRAIN_HPP
