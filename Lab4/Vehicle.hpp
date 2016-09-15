//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_VEHICLE_HPP
#define OOP3_VEHICLE_HPP

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
    double size;
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

    void setIsTurbo(const bool isTurbo) { engine_.setIsTurbo(isTurbo); }
    void setVolumeEng(const double volume) { engine_.setVolume(volume); }
    void setPowerEng(const double power) { engine_.setPower(power); }

    virtual void toConsole()
    {
        std::cout << serialNum << " " << size << std::endl;
        engine_.toConsole();
    }
};


#endif //OOP3_VEHICLE_HPP
