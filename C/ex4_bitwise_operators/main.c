/* Check how bitwise operators affect different types of variables. */
#include <stdio.h>

void main()
{
    {
        int i = 17;     // 0001 0001
        int j = 3;      // 0000 0011
        int k = i & j;  // 0000 0001
        printf("%d & %d = %d\n", i, j, k);
    }

    {
        int i = 9;      // 1001
        int j = 14;     // 1110
        int k = i | j;  // 1111
        printf("%d | %d = %d\n", i, j, k);
    }

    {
        char i = 'z';   // 0111 1010
        char j = 'f';   // 0110 0110
        char k = i | j; // 0111 1110
        printf("(%c | %c) = (%d | %d) = %d = %c\n", i, j, i, j, k, k);
    }

    {
        unsigned char i = 'a';  // 0110 0001
        unsigned char j = ~i;   // 1001 1110
        printf("~%c = ~%d = %d = %c\n", i, i, j, j);
    }

    {
        unsigned char i = 'a';       // 0110 0001
        unsigned char j = i << 1;    // 1100 0010
        printf("(%c << 1) = (%d << 1) = %d = %c\n", i, i, j, j);
    }
}
