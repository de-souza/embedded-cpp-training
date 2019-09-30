/* Check how to manipulate pointers. */
#include <stdio.h>

int main()
{
    char c = 'a';
    char *p = &c;   // use "*" to declare p as a pointer

    printf("c = '%c', *p = '%c'\n", c, *p);

    *p = 'b';   // the dereference operator "*" gives the value pointed by p

    printf("c = '%c', *p = '%c'\n", c, *p);
}
