/* Use the function scanf to read user input. */
#include <stdio.h>

int main()
{
    int i;
    char c;
    char s[128];

    printf("Please enter an integer. i = ");
    scanf("%d", &i);

    printf("Please enter a character. c = ");
    scanf(" %c", &c);  // space to ignore remaining leading whitespace

    printf("Please enter a string. s = ");
    scanf("%127s", s);

    printf("i = %d, c = %c, s = %s\n", i, c, s);
}
