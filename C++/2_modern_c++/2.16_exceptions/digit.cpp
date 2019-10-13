#include "digit.h"
#include <iostream>

Digit::Digit(const int number)
{
    if (number < 0 || number > 9)
        throw std::range_error("Error: The number must be between 0 and 9.");
    mDigit = number;
}

std::ostream& operator<<(std::ostream& os, const Digit digit)
{
    return os << digit.mDigit;
}
