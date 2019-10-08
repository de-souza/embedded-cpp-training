/* Issues with the synthetised copy constructor. */
#include "integer.h"

int main()
{
    Integer a = 5;  
    a.Print();

    Integer b = a;
    b.Print();

    b.Content = 8;
    b.Print();
}
