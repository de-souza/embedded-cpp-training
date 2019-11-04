#include "secondparent.h"
#include <iostream>
#include <string>

void SecondParent::Say(const std::string& message)
{
    std::cout << "The second parent says: " << message << '\n';
}
