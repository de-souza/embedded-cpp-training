/* How inheritance affects class constructors and destructors. */
#include "parent.h"
#include "child.h"
#include <memory>

int main()
{
    {auto pParent = std::make_unique<Parent>();}
    {auto pChild = std::make_unique<Child>("Eve");}
}
