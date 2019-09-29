/* Check how to use the sizeof unary operator. */
#include <limits.h>
#include <stdio.h>

void main()
{
    int a;
    int *b;
    unsigned long int c;
    int size;
    
    size = sizeof a * CHAR_BIT;
    printf("The size of an int is %d bytes\n", size);

    size = sizeof b * CHAR_BIT;
    printf("The size of a pointer is %d bytes\n", size);

    size = sizeof c * CHAR_BIT;
    printf("The size of an unsigned long int is %d bytes\n", size);
}
