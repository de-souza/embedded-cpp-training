/* How to use a static variable. */
#include <stdio.h>

int cnt() {
    static int i;  // initialized to 0 on first call
    return i++;
}

int main()
{
    for (int i=0; i < 10; i++)
        printf("%d\n", cnt());
}
