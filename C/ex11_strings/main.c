/* Check how strings are manipulated using strcpy and strlen. */
#include <stdio.h>
#include <string.h>

void main()
{
    char *name="Leo";
    char copy[strlen(name)];
    char memory_before[]={'B', 'e', 'f', 'o', 'r', 'e', '\0'};
    char bad_name[]={'L', 'e', 'o'};    // forget to add trailing zero
    char memory_after[]={'A', 'f', 't', 'e', 'r', '\0'};
    strcpy(copy, name);
    printf("name = %s\n", name);
    printf("copy = %s\n", copy);
    printf("strlen(name) = %d\n", (int) strlen(name));
    printf("strlen(copy) = %d\n", (int) strlen(copy));
    printf("strlen(bad_name) = %d\n", (int) strlen(bad_name));
}
