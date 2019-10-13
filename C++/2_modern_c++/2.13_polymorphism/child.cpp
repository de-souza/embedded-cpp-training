#include "child.h"
#include <iostream>

void Child::RegularDisplay()
{
    std::cout << "I am the child. (Regular)\n";
}

void Child::VirtualDisplay()
{
    std::cout << "I am the child. (Virtual)\n";
}
