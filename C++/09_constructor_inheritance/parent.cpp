#include "parent.h"
#include <iostream>

Parent::Parent()
{
    std::cout << "I am the parent." << std::endl;
}

Parent::~Parent()
{
    std::cout << "I was the parent." << std::endl;
}
