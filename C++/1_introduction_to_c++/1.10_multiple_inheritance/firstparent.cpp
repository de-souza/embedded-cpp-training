#include "firstparent.h"
#include <iostream>

FirstParent::FirstParent()
{
    std::cout << "I am the first parent." << std::endl;
}

FirstParent::~FirstParent()
{
    std::cout << "I was the first parent." << std::endl;
}

void FirstParent::Speak(const char* message)
{
    std::cout << "The first parent says: " << message << std::endl;
}
