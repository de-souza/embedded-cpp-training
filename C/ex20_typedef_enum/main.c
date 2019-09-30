/* How to use typedef and enumerations. */
#include <stdio.h>

typedef enum {
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday,
} day_t;

const char *day_from_index(const int i)
{
    switch (i) {
    case 0: return "Monday";
    case 1: return "Tuesday";
    case 2: return "Wednesday";
    case 3: return "Thursday";
    case 4: return "Friday";
    case 5: return "Saturday";
    case 6: return "Sunday";
    }
}

int main()
{
    for (day_t i=monday; i<=sunday; i++)
        printf("%s\n", day_from_index(i));
}
