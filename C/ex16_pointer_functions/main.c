/* Check how to use pointers in functions. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_date(const char *date, int *restrict day, int *restrict month, int *restrict year)
{
    char buffer[strlen(date)+1];
    strcpy(buffer, date);
    *day = strtol(strtok(buffer, "/"), NULL, 0);
    *month = strtol(strtok(NULL, "/"), NULL, 0);
    *year = strtol(strtok(NULL, "/"), NULL, 0);
}

int main()
{
    char *date = "23/03/2014";
    int day, month, year;
    parse_date(date, &day, &month, &year);
    printf("day = %d\n", day);
    printf("month = %d\n", month);
    printf("year = %d\n", year);
}
