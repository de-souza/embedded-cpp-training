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
    case 0: return "Monday\n";
    case 1: return "Tuesday\n";
    case 2: return "Wednesday\n";
    case 3: return "Thursday\n";
    case 4: return "Friday\n";
    case 5: return "Saturday\n";
    case 6: return "Sunday\n";
    }
}

int main()
{
    for (day_t i=monday; i<=sunday; i++)
        printf("%s", day_from_index(i));
}
