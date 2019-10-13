#include "child.h"
#include <iostream>

Child::Child()
{
    std::cout << "I am the child." << std::endl;
}

Child::Child(const char* name)
{
    std::cout << "I am the child. My name is " << name << "." << std::endl;
}

Child::~Child()
{
    std::cout << "I was the child." << std::endl;
}
