/* How to manipulate static variables in classes. */
#include "classwithstaticvar.h"
#include <iostream>

int main()
{
    ClassWithStaticVar counter;
    for (int i=0; i < 10; i++)
        std::cout << counter.Cnt() << std::endl;
}
