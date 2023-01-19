#pragma once
#include "LeakedObjectDetector.h"

struct Cat
{
    Cat();
    ~Cat();
    int numLimbs;
    int numTails;
    float ageYears;
    std::string colour;
    float weightKg;
    int cutenessLevel;
    int maxCroquettes;

    void meow(int loudnessDB);

    bool catchAnimal(std::string animalSpecies); 

    float throwUpFurBall(); 

    int eatCroquettes(int croquettesNum, float croquetteWeight);

    JUCE_LEAK_DETECTOR(Cat)
};
