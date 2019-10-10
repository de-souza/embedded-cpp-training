#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

class Digit
{
public:
    Digit(int number);
private:
    int mDigit;
    friend std::ostream& operator<<(std::ostream& os, const Digit digit);
};

#endif // DIGIT_H
