#include "grandparent.h"
#include <iostream>
#include <string>

void Grandparent::Say(const std::string& message)
{
    std::cout << "The grandparent says: " << message << '\n';
}
