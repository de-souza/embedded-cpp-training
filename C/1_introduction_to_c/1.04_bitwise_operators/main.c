/* How bitwise operators affect different types of variables. */
#include <stdio.h>

int main()
{
    {
        int a = 17;     // 0001 0001
        int b = 3;      // 0000 0011
        int c = a & b;  // 0000 0001
        printf("%d & %d = %d\n", a, b, c);
    }

    {
        int a = 9;      // 1001
        int b = 14;     // 1110
        int c = a | b;  // 1111
        printf("%d | %d = %d\n", a, b, c);
    }

    {
        char a = 'z';   // 0111 1010
        char b = 'f';   // 0110 0110
        char c = a | b; // 0111 1110
        printf("(%c | %c) = (%d | %d) = %d = %c\n", a, b, a, b, c, c);
    }

    {
        unsigned char a = 'a';  // 0110 0001
        unsigned char b = ~a;   // 1001 1110
        printf("~%c = ~%d = %d = %c\n", a, a, b, b);
    }

    {
        unsigned char a = 'a';       // 0110 0001
        unsigned char b = a << 1;    // 1100 0010
        printf("(%c << 1) = (%d << 1) = %d = %c\n", a, a, b, b);
    }
}
