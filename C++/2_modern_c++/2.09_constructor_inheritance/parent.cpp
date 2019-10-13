#include "parent.h"
#include <iostream>

Parent::Parent()
{
    std::cout << "I am the parent.\n";
}

Parent::~Parent()
{
    std::cout << "I was the parent.\n";
}
