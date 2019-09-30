/* Check what happens when assigning floats to ints. */
#include <stdio.h>

int main()
{
    int a = 3.7;
    printf("The value of a is %d\n", a);

    // int a = 3.7 + 7.3;   // Impossible because a is already declared
    // printf("%d\n", a);

    a = 3.7 + 7.3;
    printf("The value of a is %d\n", a);
}
