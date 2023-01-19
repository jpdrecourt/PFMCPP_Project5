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

    struct Drive;

    Drive* cDrive;

    bool bootUp(const Drive& systemDrive) const; 

    bool runProgram(const Drive& programDrive, std::string path) const; 

    bool crash() const;

    JUCE_LEAK_DETECTOR(Computer)
};
