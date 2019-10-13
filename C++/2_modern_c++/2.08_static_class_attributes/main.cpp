/* How to implement static class attributes. */
#include "hi.h"

int main()
{
    Hi::Display();  // can be used without instance
    Hi a;
    a.Display();
}
