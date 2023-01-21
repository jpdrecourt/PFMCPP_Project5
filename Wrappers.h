#pragma once

struct Cat;
struct VendingMachine;
struct Computer;
struct CatCyberOverlord;
struct CatRentalMachine;

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

struct CatRentalMachineWrapper
{
    CatRentalMachine* catRentalMachinePtr = nullptr;
    CatRentalMachineWrapper(CatRentalMachine* ptrToCatRentalMachine);
    ~CatRentalMachineWrapper();
};
