#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

class Digit
{
public:
    Digit(const int number);
    friend std::ostream& operator<<(std::ostream& os, const Digit digit);
private:
    int mDigit;
};

#endif // DIGIT_H
