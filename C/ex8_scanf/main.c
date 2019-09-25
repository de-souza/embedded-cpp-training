/* Use the function scanf to read user input. */
#include <stdio.h>

void main()
{
    int i;
    char c;
    char s[128];

    printf("Please enter an integer. i = ");
    scanf("%d", &i);

    printf("Please enter a character. c = ");
    scanf(" %c", &c);  // the leading whitespace is necessary with char

    printf("Please enter a string. s = ");
    scanf("%127s", s);

    printf("i = %d, c = %c, s = %s\n", i, c, s);
}
