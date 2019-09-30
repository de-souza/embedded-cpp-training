/* How to implement variadic functions. */
#include <stdio.h>
#include <string.h>

void printf_newline(const char *restrict format, ...)
{
    char format_newline[strlen(format+2)];
    strcpy(format_newline, format);
    strcat(format_newline, "\n");
    va_list args;
    va_start (args, format);
    vprintf (format_newline, args);
    va_end (args);
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    printf_newline("a = %d, b = %d, c = %d", a, b, c);
}
