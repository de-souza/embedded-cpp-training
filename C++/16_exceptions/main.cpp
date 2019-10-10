/* How to implement an exception handler (catch-clause). */
#include <iostream>
#include "digit.h"

int main()
{
    try {
        std::cout << "A valid digit: " << Digit(5) << std::endl;
    } catch (const std::exception& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    try {
        std::cout << "An invalid digit: " << Digit(10) << std::endl;
    } catch (const std::exception& e) {
        std::cout << std::endl << e.what() << std::endl;
    }
}
