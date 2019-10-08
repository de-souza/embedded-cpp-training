#include "secondparent.h"
#include <iostream>

SecondParent::SecondParent()
{
    std::cout << "I am the second parent." << std::endl;
}

SecondParent::~SecondParent()
{
    std::cout << "I was the second parent." << std::endl;
}

void SecondParent::Speak(const char* message)
{
    std::cout << "The second parent says: " << message << std::endl;
}
