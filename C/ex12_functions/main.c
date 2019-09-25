/* Implement various functions. */
#include <stdarg.h>
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int ascii(char c)
{
    return (int) c;
}

char Char(int i)
{
    if (i < 0 || i > 255)
        printf("The ASCII code must be between 0 and 255!\n");
    return (char) i;
}

int safe_scanf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    int r = vscanf(format, args);
    va_end(args);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}  // flush stdin
    return r;
}

int main()
{
    int a, b, i;
    char c;
    char s[128];

    printf("--- max(a, b), min(a, b) ---\n");
    printf("Please enter a number. a = ");
    while (!safe_scanf("%d", &a))
        printf("This is not a number. Please try again. a = ");
    printf("Please enter a number. b = ");
    while (!safe_scanf("%d", &b))
        printf("This is not a number. Please try again. b = ");
    printf("max(%d, %d) = %d\n", a, b, max(a,b));
    printf("min(%d, %d) = %d\n", a, b, min(a,b));

    printf("--- ascii(c) ---\n");
    printf("Please enter a character. c = ");
    safe_scanf("%c", &c);
    printf("ascii('%c') = %d\n", c, ascii(c));

    printf("--- Char(i) ---\n");
    printf("Please enter a number. i = ");
    while (!safe_scanf("%d", &i))
        printf("This is not a number. Please try again. i = ");
    printf("Char(%d) = '%c'\n", i, Char(i));

    printf("--- firstcapital(s) ---\n");
    printf("Please enter a string. s = ");
    scanf("%127[^\n]s", s);
    printf("%s\n", s);
}
