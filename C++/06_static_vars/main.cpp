/* How to implement static variables in classes. */
#include "counter.h"
#include <iostream>

int main()
{
    Counter my_counter;
    for (int i=0; i < 10; i++)
        std::cout << my_counter.Count() << '\n';
}
