#include "CatCyberOverlord.h"

CatCyberOverlord::CatCyberOverlord()
{
    std::cout << "Aliens irradiate a cat sleeping in a discarded compter - A CatCyberOverlord is born!" << std::endl;
    cat.cutenessLevel = -1000;
    computer.powerNeededW = 0;
    cat.meow(70);
}

CatCyberOverlord::~CatCyberOverlord()
{
    std::cout << "Superdog destructed the CatCyberOverlord! Hurray for Superdog!" << std::endl;
}

void CatCyberOverlord::dominateWorld(int numHours)
{
    std::cout << "Attempting to dominate the world for " << numHours << " hours\n";
    cat.cutenessLevel -= numHours;
    if (numHours > 3)
    {
        std::cout << "Failure: The cat cyberoverlord decides to take a nap instead" << std::endl;
    }
    else
    {
        std::cout << "After " << numHours << " hours of world domination, the cat cyberoverlord goes back to chasing flies and slightly redeems itself." << std::endl;
        cat.catchAnimal("Fly");
    }
}

void CatCyberOverlord::createEvilMachine(int numWings, int numTentacles)
{
    std::cout << "Attempting to build an evil machine with " << numWings << " wings and " << numTentacles << " tentacles driven by a computer with " << computer.numCPUCores << " cores\n";
    if ((numWings + numTentacles) > computer.numCPUCores)
    {
        std::cout << "The cat cyberoverlord overestimated its computer. The evil machine crashes." << std::endl;       
    }
    else
    {
        std::cout << "The cat cyberoverlord uses its evil machine to eat croquettes more efficiently." << std::endl;
        cat.maxCroquettes *= 10;
        cat.eatCroquettes(20, 1.0f);
    }   
}
