#pragma once
#include "Cat.h"
#include "VendingMachine.h"
#include "Computer.h"
#include "CatCyberOverlord.h"

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

struct ComputerWrapper
{
    Computer* computerPtr = nullptr;
    ComputerWrapper(Computer* ptrToComputer);
    ~ComputerWrapper();
};

struct CatCyberOverlordWrapper 
{
    CatCyberOverlord* catCyberOverlordPtr = nullptr;
    CatCyberOverlordWrapper(CatCyberOverlord* ptrToCatCyberOverlord);
    ~CatCyberOverlordWrapper();
};

