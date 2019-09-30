/* Check which addresses are on the stack and which are on the heap. */
#include <stdio.h>
#include <stdlib.h>

static int static_var1;
static int static_var2;
static int static_var3;
int global_var1;
int global_var2;
int global_var3;
int global_arr1[8];
int global_arr2[8];
int global_arr3[8];

void function1()
{}

void function2()
{}

void function3()
{}

int main()
{
    const int const1;
    const int const2;
    const int const3;
    int local_var1;
    int local_var2;
    int local_var3;
    int local_arr1[8];
    int local_arr2[8];
    int local_arr3[8];
    int *ptr1 = malloc(sizeof (int) * 1024);
    int *ptr2 = malloc(sizeof (int) * 1024);
    int *ptr3 = malloc(sizeof (int) * 1024);
    printf("Address of static_var1: %p\n", &static_var1);
    printf("Address of static_var2: %p\n", &static_var2);
    printf("Address of static_var3: %p\n", &static_var3);
    printf("Address of global_var1: %p\n", &global_var1);
    printf("Address of global_var2: %p\n", &global_var2);
    printf("Address of global_var3: %p\n", &global_var3);
    printf("Address of global_arr1: %p\n", global_arr1);
    printf("Address of global_arr2: %p\n", global_arr2);
    printf("Address of global_arr3: %p\n", global_arr3);
    printf("Address of function1: %p\n", &function1);
    printf("Address of function2: %p\n", &function2);
    printf("Address of function3: %p\n", &function3);
    printf("Address of const1: %p\n", &const1);
    printf("Address of const2: %p\n", &const2);
    printf("Address of const3: %p\n", &const3);
    printf("Address of local_var1: %p\n", &local_var1);
    printf("Address of local_var2: %p\n", &local_var2);
    printf("Address of local_var3: %p\n", &local_var3);
    printf("Address of local_arr1: %p\n", local_arr1);
    printf("Address of local_arr2: %p\n", local_arr2);
    printf("Address of local_arr3: %p\n", local_arr3);
    printf("Address of ptr1: %p\n", ptr1);
    printf("Address of ptr2: %p\n", ptr2);
    printf("Address of ptr3: %p\n", ptr3);
}
