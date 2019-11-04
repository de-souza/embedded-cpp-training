/* How to implement polymorphism using virtual attributes. */
#include "parent.h"
#include "child.h"
#include <memory>

int main()
{
    std::unique_ptr<Parent> pParent = std::make_unique<Parent>();
    std::unique_ptr<Parent> pChild = std::make_unique<Child>();
    pParent->RegularDisplay();  // Print "I am the parent. (Regular)"
    pChild->RegularDisplay();   // Print "I am the parent. (Regular)"
    pParent->VirtualDisplay();  // Print "I am the parent. (Virtual)"
    pChild->VirtualDisplay();   // Print "I am the child. (Virtual)"
}
