#include "digit.h"
#include <iostream>

Digit::Digit(int number)
{
    if (number < 0 || number > 9)
        throw std::range_error("OUT OF RANGE!");
    mDigit = number;
}

std::ostream& operator<<(std::ostream& os, const Digit digit)
{
    return os << digit.mDigit;
}
