/* Check the equivalence between array indexing and pointer arithmetics. */
#include <stdio.h>
#include <string.h>

void reverse_using_arr(char arr[])
{
    int len = strlen(arr);
    for (int i = 0; i < len/2; i++) {
        char temp = arr[i];
        arr[i] = arr[len-(i+1)];
        arr[len-(i+1)] = temp;
    }
}

void reverse_using_ptr(char *ptr)
{
    char *ptr_end = ptr + strlen(ptr) - 1;
    while (ptr < ptr_end) {
        char temp = *ptr;
        *ptr++ = *ptr_end;
        *ptr_end-- = temp;
    }
}

void main()
{
    char maman[] = "maman";
    char papa[] = "papa";

    printf("%s\n", maman);
    reverse_using_arr(maman);
    printf("%s\n", maman);
    reverse_using_ptr(maman);
    printf("%s\n", maman);

    printf("%s\n", papa);
    reverse_using_arr(papa);
    printf("%s\n", papa);
    reverse_using_ptr(papa);
    printf("%s\n", papa);
}
