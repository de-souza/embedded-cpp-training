/* How to implement an exception handler (catch-clause). */
#include <iostream>
#include "digit.h"

int main()
{
    try {
        std::cout << "A valid digit: " << Digit(5) << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "An invalid digit: " << Digit(10) << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
