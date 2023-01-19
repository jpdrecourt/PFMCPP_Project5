#include "VendingMachine.h"
#include "ItemDispenser.h"

VendingMachine::VendingMachine() :
kitkatDispenser ( new ItemDispenser() )
{
    std::cout << "VendingMachine being constructed" << std::endl;
}

VendingMachine::~VendingMachine()
{
    std::cout << "VendingMachine being destructed" << std::endl;
    delete kitkatDispenser;
    kitkatDispenser = nullptr;
}


float VendingMachine::chargeCustomerEuros(const ItemDispenser& item, int numberOfItems) const
{
    float priceCharged = 0.0f;
    for (int i = 0; i < numberOfItems; i++)
    {
        priceCharged += item.priceEuros;        
    }
    return priceCharged;
}

bool VendingMachine::dispenseKitkat(int numberOfItems)
{
    std::cout << "Attempt at dispensing " << numberOfItems << " items\n";
    return kitkatDispenser->distributeItems(numberOfItems);
}

void VendingMachine::refrigerate() const
{
    std::cout << (interiorTemperatureCelsius > targetTemperatureCelsius ? "Refrigeration in progress..." : "No refrigeration needed") << std::endl;
}
