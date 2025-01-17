#pragma once
#include "LeakedObjectDetector.h"

struct Computer
{
    Computer();
    ~Computer();
    int numCPUCores = 6;
    float CPUFrequencyGHz = 3.4f;
    int memoryMB = 32;
    int powerNeededW = 430;
    std::string operatingSystem = "Solaris";

    struct Drive
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

    Drive cDrive;

    bool bootUp(const Drive& systemDrive) const; 

    bool runProgram(const Drive& programDrive, std::string path) const; 

    bool crash() const;

    JUCE_LEAK_DETECTOR(Computer)
};
