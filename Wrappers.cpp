#include <iostream>
#include "Wrappers.h"

CatWrapper::CatWrapper(Cat* ptrToCat) : catPtr(ptrToCat) 
{ 
    std::cout << "+++ CatWrapper +++" << std::endl;
}

CatWrapper::~CatWrapper()
{
    delete catPtr;
    std::cout << "/// CatWrapper ///" << std::endl;
}

VendingMachineWrapper::VendingMachineWrapper(VendingMachine* ptrToVendingMachine) : vendingMachinePtr(ptrToVendingMachine)
{
    std::cout << "+++ VendingMachineWrapper +++" << std::endl;
}

VendingMachineWrapper::~VendingMachineWrapper()
{
    delete vendingMachinePtr;
    std::cout << "/// VendingMachineWrapper ///" << std::endl;
}

