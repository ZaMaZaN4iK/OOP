//
// Created by zamazan4ik on 02.09.16.
//

#ifndef OOP3_VEHICLE_HPP
#define OOP3_VEHICLE_HPP

#include <string>

class Vehicle
{
private:
    class Engine
    {
    private:
        bool isTurbo_;
        double volume_, power_;
    public:
        Engine() {}
        Engine(const double volumeEng, const double powerEng, const bool isTurbo);

        void setIsTurbo(const bool isTurbo) { isTurbo_ = isTurbo; }
        void setVolume(const double volume) { volume_ = volume; }
        void setPower(const double power) { power_ = power; }
    };

    std::string serialNum;
    double size;
    Engine engine_;
public:
    Vehicle() : engine_(Engine()) {}
    Vehicle(const double volumeEng, const double powerEng,
            const bool isTurbo, const std::string& str,
            const double abstractSize);

    void setSize(const double absSize) { size = absSize; }
    void setSerial(const std::string& str) { serialNum = str; }

    void setIsTurbo(const bool isTurbo) { engine_.setIsTurbo(isTurbo); }
    void setVolumeEng(const double volume) { engine_.setVolume(volume); }
    void setPowerEng(const double power) { engine_.setPower(power); }
};


#endif //OOP3_VEHICLE_HPP
