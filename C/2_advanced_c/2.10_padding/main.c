/* How the order of variables can affect memory use because of padding. */
#include <stdio.h>

int main()
{
    struct not_aligned {
        char ch;    // 1 byte
        double d;   // 8 bytes
        int i;      // 4 bytes
        char s[3];  // 3 bytes
    };
    struct aligned {
        double d;   // 8 bytes
        int i;      // 4 bytes
        char s[3];  // 3 bytes
        char ch;    // 1 byte
    };
    int not_aligned_size = sizeof(struct not_aligned);
    int aligned_size = sizeof(struct aligned);
    printf("not_aligned_size = %d bytes\n", not_aligned_size);
    printf("aligned_size = %d bytes\n", aligned_size);
}
