#include "ItemDispenser.h"

VendingMachine::ItemDispenser::ItemDispenser() :
name("KitKat"),
flavour("Original"),
inventory(5),
priceEuros(2.5f),
itemNumber(13),
isDisabled(false)
{
    std::cout << "VendingMachine::ItemDispenser being constructed" << std::endl;
}

VendingMachine::ItemDispenser::~ItemDispenser()
{
    std::cout << "VendingMachine::ItemDispenser being destructed" << std::endl;
}

bool VendingMachine::ItemDispenser::distributeItems(int numberOfItems)
{
    for (int i = 0; i < numberOfItems; ++i)
    {
        std::cout << "Distributing item\n";
        --inventory;
        if (inventory == 0) 
        {
            disable("Empty");
            ++i;
            return (i == numberOfItems);
        }
    }
    return true;
}

void VendingMachine::ItemDispenser::stockUp(int itemsAdded)
{
    inventory += itemsAdded;
    isDisabled = false;
}

void VendingMachine::ItemDispenser::disable(std::string cause)
{
    if (cause == "Empty") 
    {
        std::cout << "Please restock " << name << " - " << flavour << std::endl;
    }
    isDisabled = true;
}
