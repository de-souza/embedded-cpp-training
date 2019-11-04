#include "parent.h"
#include <iostream>

void Parent::RegularDisplay()
{
    std::cout << "I am the parent. (Regular)\n";
}

void Parent::VirtualDisplay()
{
    std::cout << "I am the parent. (Virtual)\n";
}
