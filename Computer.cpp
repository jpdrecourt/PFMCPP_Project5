#include "Computer.h"

Computer::Computer()
{
    std::cout << "Computer being constructed" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer being destructed" << std::endl;
}

bool Computer::bootUp(const Drive& systemDrive) const
{
    return systemDrive.readData(rand()) != 0;
}

bool Computer::runProgram(const Drive& programDrive, std::string path) const
{
    std::cout << "Running " << path << " on " << programDrive.brand << std::endl;
    return true;
}

bool Computer::crash() const
{
    if (operatingSystem == "Solaris") 
    {
        return false;
    }
    return (rand() % 1000000) == 0;
}
