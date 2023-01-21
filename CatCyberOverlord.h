#pragma once
#include "LeakedObjectDetector.h"
#include "Cat.h"
#include "Computer.h"

struct CatCyberOverlord 
{
    Cat cat;
    Computer computer;

    CatCyberOverlord();
    ~CatCyberOverlord();

    void dominateWorld(int numHours);

    void createEvilMachine(int numWings, int numTentacles);

    JUCE_LEAK_DETECTOR(CatCyberOverlord)
};
