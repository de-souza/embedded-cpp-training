/* How to use typedef and enumerations. */
#include <stdio.h>

typedef enum {mon, tue, wed, thu, fri, sat, sun} day_t;

const char *day_t_to_str(day_t d)
{
    switch (d) {
    case mon: return "Monday";
    case tue: return "Tuesday";
    case wed: return "Wednesday";
    case thu: return "Thursday";
    case fri: return "Friday";
    case sat: return "Saturday";
    case sun: return "Sunday";
    }
}

int main()
{
    for (day_t d=mon; d <= sun; d++)
        printf("%s\n", day_t_to_str(d));
}
