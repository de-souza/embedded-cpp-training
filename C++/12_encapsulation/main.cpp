/* How to encapsulate a class. */
#include "child.h"

int main()
{
    Child a;
    a.Print();
    a.Parent::Print();
}
