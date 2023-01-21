#include <iostream>
#include "Wrappers.h"
#include "Cat.h"
#include "VendingMachine.h"
#include "Computer.h"
#include "CatCyberOverlord.h"
#include "CatRentalMachine.h"

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

CatCyberOverlordWrapper::CatCyberOverlordWrapper(CatCyberOverlord* ptrToCatCyberOverlord) : catCyberOverlordPtr(ptrToCatCyberOverlord)
{
    std::cout << "+++ CatCyberOverlordWrapper +++" << std::endl;    
}

CatCyberOverlordWrapper::~CatCyberOverlordWrapper()
{
    delete catCyberOverlordPtr;
    std::cout << "/// CatCyberOverlordWrapper ///" << std::endl;
}

CatRentalMachineWrapper::CatRentalMachineWrapper(CatRentalMachine* ptrToCatRentalMachine) : catRentalMachinePtr(ptrToCatRentalMachine)
{
    std::cout << "+++ CatRentalMachineWrapper +++" << std::endl;
}

CatRentalMachineWrapper::~CatRentalMachineWrapper()
{
    delete catRentalMachinePtr;
    std::cout << "/// CatRentalMachineWrapper ///" << std::endl;
}



