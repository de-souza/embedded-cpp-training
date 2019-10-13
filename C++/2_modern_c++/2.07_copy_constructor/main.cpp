/* How a custom copy constructor can be necessary. */
#include "integer.h"

int main()
{
    Integer a = 5;  
    a.Display();

    Integer b = a;
    b.Display();

    b.content = 8;
    b.Display();  // print 8 thanks to the copy consstructor
}
