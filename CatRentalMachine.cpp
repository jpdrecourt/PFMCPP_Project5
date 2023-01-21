#include <iomanip>
#include "CatRentalMachine.h"

CatRentalMachine::CatRentalMachine(const Cat& rentalCat):
cat(rentalCat)
{
    std::cout << "Genius idea! CatRentalMachine constructed" << std::endl;
    std::cout << "Repurposing the Kitkat dispenser should be straightforward.\n";
    vendingMachine.interiorTemperatureCelsius = 25.0f;
    vendingMachine.targetTemperatureCelsius = 25.0f;
    vendingMachine.kitkatDispenser.name = "Garfield";
    vendingMachine.kitkatDispenser.flavour = cat.colour;
    vendingMachine.kitkatDispenser.inventory = 1;
    vendingMachine.kitkatDispenser.priceEuros = 50.0f;
    std::cout 
        << "New parameters: \n"
        << std::setprecision(1)
        << "Temperature: " << vendingMachine.interiorTemperatureCelsius << "\n"
        << "Product name: " << vendingMachine.kitkatDispenser.name << "\n"
        << "Product flavour: " << vendingMachine.kitkatDispenser.flavour << "\n"
        << std::setprecision(2)
        << "Product price: " <<     vendingMachine.kitkatDispenser.priceEuros << std::endl;
}

CatRentalMachine::~CatRentalMachine()
{
    std::cout << "The authorities get wind of this lucrative business. CatRentalMachine destructed" << std::endl;
}

Cat CatRentalMachine::distributeCat() const
{
    std::cout << "Distributing a cat for rental\n";
    std::cout << "His name is " << vendingMachine.kitkatDispenser.name << "\n";
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
