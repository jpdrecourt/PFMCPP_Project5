#pragma once

#include "LeakedObjectDetector.h"
#include "Cat.h"
#include "VendingMachine.h"
#include "ItemDispenser.h"

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
