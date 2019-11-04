/* How to deal with classes with diamond inheritance. */
#include "child.h"
#include <memory>

int main()
{
    Child c;
    // c.Say("Hello!");  // Ambiguous, does not compile.
    c.FirstParent::Say("Hello!");
}
