/* How to implement polymorphism using virtual attributes. */
#include "parent.h"
#include "child.h"

int main()
{
    Parent* pParentInstance = new Parent;
    Parent* pChildInstance = new Child;
    pParentInstance->Print();       // Print "I am the parent."
    pChildInstance->Print();        // Print "I am the parent."
    pParentInstance->SuperPrint();  // Print "I AM THE PARENT."
    pChildInstance->SuperPrint();   // Print "I AM THE CHILD."
    delete pParentInstance;
    delete pChildInstance;
}
