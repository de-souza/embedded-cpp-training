/* Implement various functions. */
#include <stdio.h>

int query_int(char *name)
{
    int i;
    printf("Please enter a number. %s = ", name);
    while (!scanf("%d", &i)) {
        printf("This is not a number. Please try again. %s = ", name);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}  // flush stdin
    }
    return i;
}

char query_char(char *name)
{
    char character;
    printf("Please enter a character. %s = ", name);
    scanf(" %c", &character);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return character;
}

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

int main()
{
    int a, b, i;
    char c;

    printf("### max(a, b), min(a, b) ###\n");
    a = query_int("a");
    b = query_int("b");
    printf("max(%d, %d) = %d\n", a, b, max(a,b));
    printf("min(%d, %d) = %d\n", a, b, min(a,b));

    printf("### ascii(c) ###\n");
    c = query_char("c");
    printf("ascii('%c') = %d\n", c, ascii(c));

    printf("### Char(i) ###\n");
    i = query_int("i");
    printf("Char(%d) = '%c'\n", i, Char(i));
}
