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
