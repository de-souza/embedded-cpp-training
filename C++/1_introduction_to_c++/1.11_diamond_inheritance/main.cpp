/* How to deal with constructs with diamond inheritance. */
#include "child.h"

int main()
{
    Child a;
    a.FirstParent::Speak("Hello!");  // Declare how to fetch the shared method.
}
