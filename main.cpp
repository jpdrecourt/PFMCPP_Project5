/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

#include <iostream>
#include <iomanip>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "Cat.h"
#include "VendingMachine.h"
#include "ItemDispenser.h"
#include "Computer.h"
#include "Drive.h"
#include "CatCyberOverlord.h"

/*
 new UDT 5:
 with 2 member functions
*/

struct CatRentalMachine
{
    Cat cat;
    VendingMachine vendingMachine;

    CatRentalMachine(Cat& rentalCat);
    ~CatRentalMachine();

    Cat distributeCat() const;
    void returnCat(const Cat& returnedCat) const;

    JUCE_LEAK_DETECTOR(CatRentalMachine)
};

CatRentalMachine::CatRentalMachine(Cat& rentalCat):
cat(rentalCat)
{
    std::cout << "Genius idea! CatRentalMachine constructed" << std::endl;
    std::cout << "Repurposing the Kitkat dispenser should be straightforward.\n";
    vendingMachine.interiorTemperatureCelsius = 25.0f;
    vendingMachine.targetTemperatureCelsius = 25.0f;
    vendingMachine.kitkatDispenser->name = "Garfield";
    vendingMachine.kitkatDispenser->flavour = cat.colour;
    vendingMachine.kitkatDispenser->inventory = 1;
    vendingMachine.kitkatDispenser->priceEuros = 50.0f;
    std::cout 
        << "New parameters: \n"
        << std::setprecision(1)
        << "Temperature: " << vendingMachine.interiorTemperatureCelsius << "\n"
        << "Product name: " << vendingMachine.kitkatDispenser->name << "\n"
        << "Product flavour: " << vendingMachine.kitkatDispenser->flavour << "\n"
        << std::setprecision(2)
        << "Product price: " <<     vendingMachine.kitkatDispenser->priceEuros << std::endl;
}

CatRentalMachine::~CatRentalMachine()
{
    std::cout << "The authorities get wind of this lucrative business. CatRentalMachine destructed" << std::endl;
}

Cat CatRentalMachine::distributeCat() const
{
    std::cout << "Distributing a cat for rental\n";
    std::cout << "His name is " << vendingMachine.kitkatDispenser->name << "\n";
    return cat;
}

void CatRentalMachine::returnCat(const Cat& returnedCat) const
{
    if (returnedCat.colour != cat.colour)
    {
        std::cout << "You are trying to return the wrong cat!" << std::endl;
    }
    else
    {
        std::cout << "Cat safely returned! Thanks for using our services!" << std::endl;
    }
}

struct CatRentalMachineWrapper
{
    CatRentalMachine* catRentalMachinePtr;
    CatRentalMachineWrapper(CatRentalMachine* ptrToCatRentalMachine) : catRentalMachinePtr(ptrToCatRentalMachine)
    {
        std::cout << "+++ CatRentalMachineWrapper +++" << std::endl;
    }
    ~CatRentalMachineWrapper()
    {
        delete catRentalMachinePtr;
        std::cout << "/// CatRentalMachineWrapper ///" << std::endl;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    CatWrapper catWrapper( new Cat() );
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << catWrapper.catPtr->numLimbs << " limb(s) and " << catWrapper.catPtr->numTails << " tail(s). It is " << catWrapper.catPtr->ageYears << " year(s) old. Its colour is " << catWrapper.catPtr->colour << ". And its cuteness level is " << catWrapper.catPtr->cutenessLevel << ".\n"
        << "Cat weight: " << catWrapper.catPtr->weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << catWrapper.catPtr->maxCroquettes << "\n";
    std::cout  << "--- ";
    catWrapper.catPtr->meow(25);
    
    std::cout
        << "--- "
        << "Did the cat catch a fly? " << (catWrapper.catPtr->catchAnimal("Fly") ? "Yes!" : "No :(") << "\n"
        << "--- "
        << "Size of the furball: " << catWrapper.catPtr->throwUpFurBall() << "mm\n"
        << "--- Attempting to eat 11 croquettes in bowl\n"
        << catWrapper.catPtr->eatCroquettes(11, 1) << " croquette(s) left in bowl\n"
        << std::setprecision(3)
        << "Cat new weight: " << catWrapper.catPtr->weightKg << "\n"
        << std::endl;
    
    VendingMachineWrapper vendingMachineWrapper( new VendingMachine() );
    std::cout 
        << std::setprecision(1)
        << "Vending machine on: " << (vendingMachineWrapper.vendingMachinePtr->isOn ? "Yes" : "No") << "\n"
        << "Interior temperature: " << vendingMachineWrapper.vendingMachinePtr->interiorTemperatureCelsius << "°C" << "\n"
        << "Target temperature: " << vendingMachineWrapper.vendingMachinePtr->targetTemperatureCelsius << "°C" << "\n"
        << "--- ";
    vendingMachineWrapper.vendingMachinePtr->refrigerate();
    std::cout << std::setprecision(2) 
        << "Cash collected: " << vendingMachineWrapper.vendingMachinePtr->cashCollectedEuros << "€\n" 
        << "Item selected: " << vendingMachineWrapper.vendingMachinePtr->itemSelected << "\n"
        << "--- "
        << "Charging customer for 5 items: " << vendingMachineWrapper.vendingMachinePtr->chargeCustomerEuros(*vendingMachineWrapper.vendingMachinePtr->kitkatDispenser, 5) << "€\n"
        << "*** Dispenser number: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->itemNumber << "\n"
        << "*** "
        << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->isDisabled ? "Disabled" : "Activated") << "\n"
        << "*** Product: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->name << "\n"
        << "*** Flavour: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->flavour << "\n"
        << "*** Inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->inventory << "\n"
        << "*** Price: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->priceEuros << "€\n"
        << "--- "
        << (vendingMachineWrapper.vendingMachinePtr->dispenseKitkat(6) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser state: " << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->isDisabled ? "Disabled" : "Activated") << "\n";
    
    vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->stockUp(3);
    std::cout 
        << "--- "
        << "New item dispenser inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->inventory << "\n"
        << "New item dispenser state: " << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->isDisabled ? "Disabled" : "Activated") << "\n"
        << "--- "
        << (vendingMachineWrapper.vendingMachinePtr->dispenseKitkat(2) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser->inventory << "\n";
    
    std::cout << std::endl;
    ComputerWrapper computerWrapper( new Computer() );
    std::cout 
        << "--- "
        << "Computer booted: " << (computerWrapper.computerPtr->bootUp(*computerWrapper.computerPtr->cDrive) ? "Yes" : "No") << "\n"
        << "Number of cores: " << computerWrapper.computerPtr->numCPUCores << "\n"
        << "CPU Frequency: " << computerWrapper.computerPtr->CPUFrequencyGHz << "GHz\n"
        << "RAM: " << computerWrapper.computerPtr->memoryMB << "MB\n"
        << "Power needed: " << computerWrapper.computerPtr->powerNeededW << "W\n"
        << "Operating system: " << computerWrapper.computerPtr->operatingSystem << "\n"
        << "*** Drive brand: " << computerWrapper.computerPtr->cDrive->brand << "\n"
        << "*** Drive capacity: " << computerWrapper.computerPtr->cDrive->capacityGB << "GB\n"
        << "*** Drive RPM: " << computerWrapper.computerPtr->cDrive->standardRpm << "\n"
        << "*** Drive read speed: " << computerWrapper.computerPtr->cDrive->readSpeedMBs << "MB/s\n"
        << "--- "
        << "*** Data read at address 123: " << computerWrapper.computerPtr->cDrive->readData(123) << "\n"
        << "--- "
        << "*** Writing data 456 at address 678 successful?: " << (computerWrapper.computerPtr->cDrive->writeData(678, 456) ? "Yes" : "No") << "\n"
        << "--- ";
    computerWrapper.computerPtr->runProgram(*computerWrapper.computerPtr->cDrive, "/usr/local/games/pacman/pacman");
    std::cout 
        << "--- "
        << "Computer crashed: " << (computerWrapper.computerPtr->crash() ? "Yes :(" : "No") << "\n"
        << "--- ";
    computerWrapper.computerPtr->cDrive->parkHeads();
    std::cout << std::endl;
    
    CatCyberOverlordWrapper catCyberOverlordWrapper( new CatCyberOverlord() );
    catCyberOverlordWrapper.catCyberOverlordPtr->dominateWorld(5);
    std::cout << "New cuteness level: " << catCyberOverlordWrapper.catCyberOverlordPtr->cat.cutenessLevel << std::endl;
    catCyberOverlordWrapper.catCyberOverlordPtr->dominateWorld(2);
    std::cout << "New cuteness level: " << catCyberOverlordWrapper.catCyberOverlordPtr->cat.cutenessLevel << std::endl;
    catCyberOverlordWrapper.catCyberOverlordPtr->createEvilMachine(2, 6);
    std::cout << "Who needs wings? 6 tentacles will do!\n";
    catCyberOverlordWrapper.catCyberOverlordPtr->createEvilMachine(0, 6);
    std::cout << std::endl;
    
    CatWrapper rentalCatWrapper( new Cat() );
    rentalCatWrapper.catPtr->numLimbs = 4;
    rentalCatWrapper.catPtr->cutenessLevel = 150;
    rentalCatWrapper.catPtr->maxCroquettes = 12345;
    rentalCatWrapper.catPtr->colour = "orange";
    CatRentalMachineWrapper catRentalMachineWrapper( new CatRentalMachine(*rentalCatWrapper.catPtr) );
    Cat myRentalCat = catRentalMachineWrapper.catRentalMachinePtr->distributeCat();
    std::cout << "What a beautiful cat!\n";
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << myRentalCat.numLimbs << " limb(s) and " << myRentalCat.numTails << " tail(s). It is " << myRentalCat.ageYears << " year(s) old. Its colour is " << myRentalCat.colour << ". And its cuteness level is " << myRentalCat.cutenessLevel << ".\n"
        << "Cat weight: " << myRentalCat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << myRentalCat.maxCroquettes << "\n"
        << "This cat is too cute, I'll return a grey cat instead....\n";
    CatWrapper randomCatWrapper( new Cat() );
    catRentalMachineWrapper.catRentalMachinePtr->returnCat(*randomCatWrapper.catPtr);
    
    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
