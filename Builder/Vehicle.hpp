#pragma once

#include <iostream>
#include <memory>

class Vehicle {
    public:
    std::string Engine;
    std::string Color;
    std::string TranmissionType;
    bool Gps;
};

class Car : public Vehicle {
    public:
    Car() = default;
    bool AllWheelDrive;
};

class Bike : public Vehicle {
    public:
    Bike() = default;
    unsigned int EngineCC;
};

