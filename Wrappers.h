#pragma once
#include "Cat.h"
#include "VendingMachine.h"

struct CatWrapper
{
    Cat* catPtr = nullptr;
    CatWrapper(Cat* ptrToCat); 
    ~CatWrapper();
};

struct VendingMachineWrapper
{
    VendingMachine* vendingMachinePtr = nullptr;
    VendingMachineWrapper(VendingMachine* ptrToVendingMachine);
    ~VendingMachineWrapper();
};
