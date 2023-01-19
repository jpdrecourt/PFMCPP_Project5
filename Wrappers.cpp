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

ComputerWrapper::ComputerWrapper(Computer* ptrToComputer) : computerPtr(ptrToComputer)
{
    std::cout << "+++ ComputerWrapper +++" << std::endl;
}

ComputerWrapper::~ComputerWrapper()
{
    delete computerPtr;
    std::cout << "/// ComputerWrapper ///" << std::endl;
}
