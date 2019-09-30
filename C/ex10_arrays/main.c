/* Check how to manipulate arrays. */
#include <stdio.h>

int main()
{
    int size=30, arr[size], inv_arr[size];
    arr[0] = inv_arr[size-1] = 1;
    for (int i=1; i < size; i++)
        arr[i] = inv_arr[size-(i+1)] = 2 * arr[i-1];
    for (int i=0; i < size; i++)
        printf("arr[%d] = %d, inv_arr[%d] = %d\n", i, arr[i], i, inv_arr[i]);
}
