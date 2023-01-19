#include <iostream>
#include <iomanip>
#include "Cat.h"

Cat::Cat() :
numLimbs(3),
numTails(1),
ageYears(3.6f),
colour("grey"),
weightKg(4.1f),
cutenessLevel(50),
maxCroquettes(7)
{
    std::cout << "Cat is born" << std::endl;
}

Cat::~Cat() 
{
    if (cutenessLevel < 0)
    {
        std::cout << "Cat is gone to cat hell" << std::endl;
    }
    else
    {
        std::cout << "Cat is gone to cat heaven" << std::endl;
    }
}


void Cat::meow(const int loudnessDB)
{
    std::cout << "Meow!!! " << loudnessDB << " dB" << std::endl;
    if (loudnessDB < 30)
    {
        cutenessLevel += 10;
    }
    else
    {
        cutenessLevel -= loudnessDB;        
    }
    std::cout << "My current cuteness level is " << cutenessLevel << std::endl;
}

bool Cat::catchAnimal(const std::string animalSpecies)
{
    if (animalSpecies == "Fly")
    {
        cutenessLevel += 10;
        return true;
    }
    cutenessLevel -= 10;
    return false;
}

float Cat::throwUpFurBall()
{
    cutenessLevel -= 50;
    return weightKg * 11;
}

int Cat::eatCroquettes(const int croquettesNum, const float croquetteWeightG)
{
    int i = 0;
    while (i < croquettesNum)
    {
        ++i;
        weightKg += croquetteWeightG * 0.001f;
        std::cout << "Eating a croquette... yum!\n";
        if (i >= maxCroquettes) 
        {
            std::cout << "I had enough.\n";
            return croquettesNum - i;
        }
    }
    return 0;
}
