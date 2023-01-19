#pragma once
#include "VendingMachine.h"

struct VendingMachine::ItemDispenser
{
    ItemDispenser();
    ~ItemDispenser();
    std::string name = "KitKat";
    std::string flavour = "Original";
    int inventory = 5;
    float priceEuros = 2.5f;
    int itemNumber = 13;
    bool isDisabled = false;

    bool distributeItems(int numberOfItems); 

    void stockUp(int itemsAdded); 

    void disable(std::string cause); 
};
