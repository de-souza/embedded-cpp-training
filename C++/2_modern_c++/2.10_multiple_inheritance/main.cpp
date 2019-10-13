/* How multiple inheritances can cause ambiguous method calls. */
#include "child.h"
#include <memory>

int main()
{
    auto p = std::make_unique<Child>();
    // p->Say("Hello!");  // Ambiguous, does not compile.
    p->FirstParent::Say("Hello!");
    p->SecondParent::Say("Hello!");
}
