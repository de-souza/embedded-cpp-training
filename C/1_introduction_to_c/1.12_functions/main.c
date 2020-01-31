/* How to manipulate functions. */
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
        puts("The ASCII code must be between 0 and 255!");
    return (char) i;
}

void capitalize(char *restrict s)
{
    s[0] = toupper(s[0]);
}

void uppercase(char *restrict s)
{
    for (int i=0; s[i]; i++)
        s[i] = toupper(s[i]);
}

void lowercase(char *restrict s)
{
    for (int i=0; s[i]; i++)
        s[i] = tolower(s[i]);
}

void flush_stdin()
{
    while (getchar() != '\n');
}

void query_string(char *restrict s, const char *restrict message)
{
    printf("%s", message);
    fgets(s, STR_LEN, stdin);
    size_t idx_newline = strcspn(s, "\n");
    while (s[idx_newline] != '\n') {
        printf("Maximum %d characters. Please try again : ", STR_LEN - 2);
        flush_stdin();
        fgets(s, STR_LEN, stdin);   
        idx_newline = strcspn(s, "\n");
    }
    s[idx_newline] = 0;
}

int query_number(const char *restrict message)
{
    char input[STR_LEN], *remainer;
    query_string(input, message);
    int n = strtol(input, &remainer, 0);
    while (strlen(remainer) || remainer == input) {
        query_string(input, "Not a number. Please try again : ");
        n = strtol(input, &remainer, 0);
    }
    return n;
}

char query_character(const char *restrict message)
{
    char input[STR_LEN];
    query_string(input, message);
    while (strlen(input) != 1)
        query_string(input, "Not a character. Please try again : ");
    return input[0];
}

int main()
{
    int a, b, i;
    char c;
    char s[STR_LEN];

    puts("--- max(a, b), min(a, b) ---");
    a = query_number("Please enter a number. a = ");
    b = query_number("Please enter a number. b = ");
    printf("max(%d, %d) = %d\n", a, b, max(a,b));
    printf("min(%d, %d) = %d\n", a, b, min(a,b));

    puts("--- ascii(c) ---");
    c = query_character("Please enter a character. c = ");
    printf("ascii('%c') = %d\n", c, ascii(c));

    puts("--- Char(i) ---");
    i = query_number("Please enter a number. i = ");
    printf("Char(%d) = '%c'\n", i, Char(i));

    puts("--- capitalize(s) ---");
    query_string(s, "Please enter a string. s = ");
    capitalize(s);
    printf("capitalize(s) => s = %s\n", s);
    
    puts("--- uppercase(s) ---");
    query_string(s, "Please enter a string. s = ");
    uppercase(s);
    printf("uppercase(s) => s = %s\n", s);
    
    puts("--- lowercase(s) ---");
    query_string(s, "Please enter a string. s = ");
    lowercase(s);
    printf("lowercase(s) => s = %s\n", s);
}
