#include "Computer.h"

Computer::Drive::Drive()
{
    std::cout << "Computer::Drive being constructed" << std::endl;
}

Computer::Drive::~Drive()
{
    std::cout << "Computer::Drive being destructed" << std::endl;
}

int Computer::Drive::readData(const int address) const
{
    return address * rand();
}

bool Computer::Drive::writeData(const int address, int data) const
{
    return ((rand() * address * data) % 1000000) != 0; // Very bad harddrive!
}

void Computer::Drive::parkHeads() const
{
    std::cout << ((rand() % 1000000) != 0 ? "Heads parked" : "Failed to park heads!") << std::endl;
}
