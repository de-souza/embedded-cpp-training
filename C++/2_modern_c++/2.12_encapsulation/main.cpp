/* How to access a method from a parent class. */
#include "child.h"

int main()
{
    Child a;
    a.Display();
    a.Parent::Display();
}
