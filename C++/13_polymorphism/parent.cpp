#include "parent.h"
#include <iostream>

void Parent::Print()
{
    std::cout << "I am the parent." << std::endl;
}

void Parent::SuperPrint()
{
    std::cout << "I AM THE PARENT." << std::endl;
}

Parent::~Parent() {}
