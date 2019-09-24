/* Check how scoping affects variables. */
#include <stdio.h>

void main()
{
    int i=5;
    printf("The value of i is %d\n", i);
    {
        int i=8;
        printf("The value of i is %d\n", i);
    }
    printf("The value of i is %d\n", i);
}
