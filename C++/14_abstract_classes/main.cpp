/* How to implement abstract classes. */
#include "abstractparent.h"
#include "child.h"
#include <memory>

int main()
{
    std::unique_ptr<AbstractParent> p = std::make_unique<Child>();
    p->Display();
}
