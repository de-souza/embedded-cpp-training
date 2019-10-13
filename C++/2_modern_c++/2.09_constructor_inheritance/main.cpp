/* How inheritance affects class constructors and destructors. */
#include "parent.h"
#include "child.h"
#include <memory>

int main()
{
    {auto parent = std::make_unique<Parent>();}
    {auto child = std::make_unique<Child>("Eve");}
}
