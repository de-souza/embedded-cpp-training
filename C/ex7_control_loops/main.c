/* Use a control loop to display characters a to z and their ASCII code. */
#include <stdio.h>

void main()
{
    printf("Characters a to z and their ASCII code:\n");
    for (char c='a'; c <= 'z'; c++)
        printf("%c: %d\n", c, c);
}
