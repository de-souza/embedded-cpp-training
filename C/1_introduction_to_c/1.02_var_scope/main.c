/* How scoping affects variables. */
#include <stdio.h>

int main()
{
    int a = 5;
    printf("The value of a is %d\n", a);
    {
        int a = 8;
        printf("The value of a is %d\n", a);
    }
    printf("The value of a is %d\n", a);
}
