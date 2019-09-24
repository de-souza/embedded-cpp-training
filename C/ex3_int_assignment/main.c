/* Check what happens when assigning floats to ints. */
#include <stdio.h>

void main()
{
    int i = 3.7;
    printf("The value of i is %d\n",i);

    // int i = 3.7 + 7.3;   // Impossible because i is already declared
    // printf("%d\n",i);

    i = 3.7 + 7.3;
    printf("The value of i is %d\n",i);
}
