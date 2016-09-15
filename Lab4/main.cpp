#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "json/json.h"

#include "Auto.hpp"
#include "Express.hpp"
#include "Train.hpp"
#include "Vehicle.hpp"
#include "Carriage.hpp"
#include "Printer.hpp"

class A
{
public:
    virtual void print(){}
};

class B : public A
{

};

void prepareJsonData()
{
    std::ofstream outFile("input.json");

    Json::Value out;
    Json::Value cars(Json::arrayValue);

    Json::Value car1, car2;
    car1["serial"] = "1488HH_WhitePower";
    car1["volume"] = 322.0;
    car2["serial"] = "zamazan4ik";
    car2["volume"] = 228.0;

    cars.append(car1);
    cars.append(car2);


    out["automobile"]["serial"] = "BigRussianBoss";
    out["automobile"]["size"] = 100500.0;
    out["automobile"]["volumeEngine"] = 4.2;
    out["automobile"]["powerEngine"] = 228.0;
    out["automobile"]["isTurbo"] = 1;
    out["automobile"]["isTO"] = 0;

    out["express"]["serial"] = "Azazin Kreet";
    out["express"]["size"] = 10000.0;
    out["express"]["volumeEngine"] = 42.0;
    out["express"]["powerEngine"] = 500.0;
    out["express"]["isTurbo"] = 1;
    out["express"]["carriages"] = cars;
    out["express"]["turbospeed"] = 1;


    outFile << out;
    outFile.close();
}

int main()
{
    prepareJsonData();

    //Read from .json
    std::ifstream input("input.json", std::ifstream::binary);
    input.seekg(0, std::ios::end);
    size_t size = input.tellg();
    std::string buffer(size, ' ');
    input.seekg(0);
    input.read(&buffer[0], size);

    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(buffer, root, false);
    if(!parsedSuccess)
    {
        std::cerr << "Failed to parse JSON" << std::endl;
        return 1;
    }


    Auto automobile;
    //Setting
    automobile.setSerial(root["automobile"]["serial"].asString());
    automobile.setTO(root["automobile"]["isTO"].asBool());
    automobile.setSize(root["automobile"]["size"].asDouble());
    automobile.setPowerEng(root["automobile"]["powerEngine"].asDouble());
    automobile.setVolumeEng(root["automobile"]["volumeEngine"].asDouble());
    automobile.setIsTurbo(root["automobile"]["isTurbo"].asBool());

    //end

    std::vector<Carriage> vec;
    Express express;
    express.setSerial(root["express"]["serial"].asString());
    express.setTurboSpeed(root["automobile"]["turbospeed"].asBool());
    express.setSize(root["express"]["size"].asDouble());
    express.setPowerEng(root["express"]["powerEngine"].asDouble());
    express.setVolumeEng(root["express"]["volumeEngine"].asDouble());
    express.setIsTurbo(root["express"]["isTurbo"].asBool());

    Json::Value cars;
    cars = root["express"]["carriages"];
    for(int i = 0; i < cars.size(); ++i)
    {
        Carriage car;
        car.setSerial(cars[i]["serial"].asString());
        car.setVolume(cars[i]["volume"].asDouble());
        vec.emplace_back(std::move(car));
    }
    express.setCarriages(vec);
    express.printSomeMagicValue();
    Express::printObjectsCount();

    //Casts demonstrating begin
    int a = 5;
    double b;
    int* ptrA;
    const int* ptrB;
    A* ptrclA = new A;
    B* ptrclB = new B;
    b = static_cast<double>(a);
    ptrA = const_cast<int*>(ptrB);
    ptrclA = ptrclB;//ok
    ptrclB = dynamic_cast<B*>(ptrclA);//now ok
    //Also we can use reinterpret_cast (like C-style casting)
    //end

    //Demonstrating printer
    std::vector<AbstractVehicle*> forTest({new Auto, new Express, new Train, new Vehicle});
    Printer printer;
    for(const auto ptr : forTest)
    {
        printer.iAmPrinting(ptr);
    }
    //end

    return 0;
}