#pragma once
#include "Cat.h"

struct CatWrapper
{
    Cat* catPtr = nullptr;
    CatWrapper(Cat* ptrToCat); 
    ~CatWrapper();
};
