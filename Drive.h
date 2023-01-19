#pragma once
#include "LeakedObjectDetector.h"
#include "Computer.h"

struct Computer::Drive
{
    Drive();
    ~Drive();
    std::string brand = "Seagate";
    float capacityGB = 2000.0f;
    int standardRpm = 7200;
    float readSpeedMBs = 101.1f;
    float writeSpeedMs = 74.2f;

    int readData(int address) const; 
    
    bool writeData(int address, int data) const; 

    void parkHeads() const; 
};
