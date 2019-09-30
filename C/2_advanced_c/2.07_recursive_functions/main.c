/* How to implement recursive functions. */
#include <stdio.h>

int power(int base, int exp)
{
    switch (exp) {
    default: return base * power(base, exp-1);
    case 1: return base;
    case 0: return 1;
    }
}

int main()
{
    int base = 2;
    int exp = 6;
    int result = power(base, exp);
    printf("%d\n", result);
}
