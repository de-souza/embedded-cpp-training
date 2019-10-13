#include "child.h"
#include <iostream>

Child::Child()
{
    std::cout << "I am the child." << std::endl;
}

Child::~Child()
{
    std::cout << "I was the child." << std::endl;
}
