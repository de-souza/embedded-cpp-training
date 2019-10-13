#include "child.h"
#include <iostream>

Child::Child()
{
    std::cout << "I am the child.\n";
}

Child::Child(const std::string& name)
{
    std::cout << "I am the child. My name is " << name << ".\n";
}

Child::~Child()
{
    std::cout << "I was the child.\n";
}
