#pragma once
#include "LeakedObjectDetector.h"

struct VendingMachine
{
    VendingMachine();
    ~VendingMachine();
    bool isOn = true;
    float interiorTemperatureCelsius = 10.2f;
    float targetTemperatureCelsius = 8.5f;
    float cashCollectedEuros = 123.54f;
    int itemSelected = 13;

    struct ItemDispenser
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

    ItemDispenser kitkatDispenser;

    float chargeCustomerEuros(const ItemDispenser& item, int numberOfItems) const; 

    bool dispenseKitkat(int numberOfItems); 

    void refrigerate() const;

    JUCE_LEAK_DETECTOR(VendingMachine)
};
