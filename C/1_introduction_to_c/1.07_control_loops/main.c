/* Use a control loop to display characters a-z and their ASCII code. */
#include <stdio.h>

int main()
{
    puts("Characters a-z and their ASCII code:");
    for (char c='a'; c <= 'z'; c++)
        printf("%c: %d\n", c, c);
}
