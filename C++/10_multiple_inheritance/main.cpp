/* How multiple inheritances can create ambiguous method calls. */
#include "child.h"

int main()
{
    Child* p = new Child;
    // p->Speak("Hello!");  // Ambiguous, does not compile.
    p->FirstParent::Speak("Hello!");
    p->SecondParent::Speak("Hello!");
    delete p;
}
