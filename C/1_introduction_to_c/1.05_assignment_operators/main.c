/* How to assign values to variables. */
#include <stdio.h>

int main()
{
    int a = 3, b, c;

    a += 4;     // assignment operator (also -= *= /= %= &= ˆ= |= <<= >>=)
    printf("a = %d\n", a);

    b = ++a;    // incrementation after assignment (unary operator)
    printf("a = %d and b = %d\n", a, b);

    c = a++;    // incrementation before assignment (unary operator)
    printf("a = %d and c = %d\n", a, c);
}
