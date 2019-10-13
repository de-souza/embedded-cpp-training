/* How multiple inheritances can cause ambiguous method calls. */
#include "child.h"
#include <memory>

int main()
{
    Child c;
    // c.Say("Hello!");  // Ambiguous, does not compile.
    c.FirstParent::Say("Hello!");
    c.SecondParent::Say("Hello!");
}
