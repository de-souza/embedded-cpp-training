/* Check how to use the sizeof unary operator. */
#include <limits.h>
#include <stdio.h>

void main()
{
    int a = 0;
    int size = sizeof(a) * CHAR_BIT;
    printf("The size of an int is %d bytes\n", size);

    int *b = &a;
    size = sizeof(b) * CHAR_BIT;
    printf("The size of a pointer is %d bytes\n", size);

    unsigned long int c = 0;
    size = sizeof(c) * CHAR_BIT;
    printf("The size of an unsigned long int is %d bytes\n", size);
}
