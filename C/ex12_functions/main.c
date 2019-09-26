/* Implement various functions. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_LEN 128

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

void capitalize(char *restrict s)
{
    s[0] = toupper(s[0]);
}

void uppercase(char *restrict s)
{
    int i = 0;
    while (s[i]) {
        s[i] = toupper(s[i]);
        i++;
    }
}

void lowercase(char *restrict s)
{
    int i = 0;
    while (s[i]) {
        s[i] = tolower(s[i]);
        i++;
    }
}

void query_string(char *restrict s, const char *restrict message, const char *restrict name)
{
    printf((message ? message : "Please enter a string. %s = "), name);
    fgets(s, STR_LEN, stdin);
    s[strcspn(s, "\n")] = 0;
}

int query_number(const char *restrict name)
{
    int n;
    char input[STR_LEN], *remainer;
    query_string(input, "Please enter a number. %s = ", name);
    n = strtol(input, &remainer, 0);
    while (strlen(remainer) || remainer == input) {
        query_string(input, "Not a number. Please try again. %s = ", name);
        n = strtol(input, &remainer, 0);
    }
    return n;
}

char query_character(const char *restrict name)
{
    char input[STR_LEN];
    query_string(input, "Please enter a character. %s = ", name);
    while (strlen(input) != 1) {
        query_string(input, "Not a character. Please try again. %s = ", name);
    }
    return input[0];
}

void main()
{
    int a, b, i;
    char c;
    char s[STR_LEN];

    printf("--- max(a, b), min(a, b) ---\n");
    a = query_number("a");
    b = query_number("b");
    printf("max(%d, %d) = %d\n", a, b, max(a,b));
    printf("min(%d, %d) = %d\n", a, b, min(a,b));

    printf("\n--- ascii(c) ---\n");
    c = query_character("c");
    printf("ascii('%c') = %d\n", c, ascii(c));

    printf("\n--- Char(i) ---\n");
    i = query_number("i");
    printf("Char(%d) = '%c'\n", i, Char(i));

    printf("\n--- capitalize(s) ---\n");
    query_string(s, 0, "s");
    capitalize(s);
    printf("firstcapital(s) => s = %s\n", s);
    
    printf("\n--- uppercase(s) ---\n");
    query_string(s, 0, "s");
    uppercase(s);
    printf("uppercase(s) => s = %s\n", s);
    
    printf("\n--- lowercase(s) ---\n");
    query_string(s, 0, "s");
    lowercase(s);
    printf("lowercase(s) => s = %s\n", s);
}
