//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_VEHICLE_HPP
#define OOP3_VEHICLE_HPP

#include <iostream>
#include <string>

#include "AbstractVehicle.hpp"

class Vehicle : public AbstractVehicle
{
private:
    class Engine
    {
    private:
        bool isTurbo_;
        double volume_, power_;
        Vehicle* parent_;
    public:
        bool onlyForParent = false;

        Engine(Vehicle* parent) : parent_(parent) { iCanCallOutsideMethod(); }
        Engine(const double volumeEng, const double powerEng, const bool isTurbo);

        void setIsTurbo(const bool isTurbo) { isTurbo_ = isTurbo; }
        void setVolume(const double volume) { volume_ = volume; }
        void setPower(const double power) { power_ = power; }

        double getVolume() const { return volume_; }

        void iCanCallOutsideMethod()
        {
            parent_->meCanCallNestedClass();
        }

        void toConsole()
        {
            std::cout << isTurbo_ << " " << volume_ << " " << power_ << std::endl;
        }
    };

    std::string serialNum;
    double size, cost_, speed_;
    Engine engine_;

    void meCanCallNestedClass();
    void checkNestedClass();
public:
    Vehicle() : engine_(Engine(this)) { checkNestedClass(); }
    Vehicle(const double volumeEng, const double powerEng,
            const bool isTurbo, const std::string& str,
            const double abstractSize);

    void setSize(const double absSize) { size = absSize; }
    void setSerial(const std::string& str) { serialNum = str; }
    void setCost(const double cost) { cost_ = cost; }
    void setSpeed(const double speed) { speed_ = speed; }

    void setIsTurbo(const bool isTurbo) { engine_.setIsTurbo(isTurbo); }
    void setVolumeEng(const double volume) { engine_.setVolume(volume); }
    void setPowerEng(const double power) { engine_.setPower(power); }

    double getCost() const { return cost_; }
    double getVolumeEng() const { return engine_.getVolume(); }
    double getSpeed() const { return speed_; }

    bool operator<(const Vehicle& val) const
    {
        return serialNum < val.serialNum;
    }

    virtual void toConsole()
    {
        std::cout << serialNum << " " << size << std::endl;
        engine_.toConsole();
    }

};


#endif //OOP3_VEHICLE_HPP
