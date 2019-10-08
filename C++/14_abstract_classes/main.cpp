/* How to implement abstract classes. */
#include "abstractparent.h"
#include "child.h"

int main()
{
    AbstractParent* pChildInstance = new Child;
    pChildInstance->Print();
}
