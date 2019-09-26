/* Implement various functions. */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int max(const int a, const int b)
{
    return a > b ? a : b;
}

int min(const int a, const int b)
{
    return a < b ? a : b;
}

int ascii(const char c)
{
    return (int) c;
}

char Char(const int i)
{
    if (i < 0 || i > 255)
        printf("The ASCII code must be between 0 and 255!\n");
    return (char) i;
}

char capital(char c)
{
    return ('a' <= c || c <= 'z') ? c - 32 : c;
}

void capitalize(char *restrict s)
{
    s[0] = capital(s[0]);
}

int safe_scanf(const char *restrict format, ...)
{
    int c, r;
    va_list args;
    va_start(args, format);
    r = vscanf(format, args);
    va_end(args);
    while ((c = getchar()) != '\n' && c != EOF) {}  // flush stdin
    return r;
}

void main()
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

    printf("\n--- ascii(c) ---\n");

    printf("Please enter a character. c = ");
    safe_scanf("%c", &c);
    printf("ascii('%c') = %d\n", c, ascii(c));

    printf("\n--- Char(i) ---\n");

    printf("Please enter a number. i = ");
    while (!safe_scanf("%d", &i))
        printf("This is not a number. Please try again. i = ");
    printf("Char(%d) = '%c'\n", i, Char(i));

    printf("\n--- capitalize(s) ---\n");

    printf("Please enter a string. s = ");
    safe_scanf("%127[^\n]", s);
    capitalize(s);
    printf("firstcapital(s) => s = %s\n", s);
}
