#include "grandparent.h"
#include <iostream>

GrandParent::GrandParent()
{
    std::cout << "I am the grandparent." << std::endl;
}

void GrandParent::Speak(const char* message)
{
    std::cout << "The grandparent says: " << message << std::endl;
}
