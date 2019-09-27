/* Check how to act on pointers with functions. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_date(const char *date, int *day, int *month, int *year)
{
    char s_day[3];
    char s_month[3];
    char s_year[5];
    strncpy(s_day, date, 2);
    strncpy(s_month, date+3, 2);
    strncpy(s_year, date+6, 4);
    *day = strtol(s_day, NULL, 0);
    *month = strtol(s_month, NULL, 0);
    *year = strtol(s_year, NULL, 0);
}

void main()
{
    char *date = "23/03/2014";
    int day, month, year;
    parse_date(date, &day, &month, &year);
    printf("day = %d\n", day);
    printf("month = %d\n", month);
    printf("year = %d\n", year);
}
