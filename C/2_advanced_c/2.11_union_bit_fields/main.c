/* How to create bit fields, and how to associate types using unions. */
#include <stdio.h>

int main()
{
    struct bit_fields {
        unsigned first_bit: 1;
        unsigned last_seven_bits : 7;
    };
    union my_union {
        struct bit_fields as_bits;
        char as_char;
    } value;
    value.as_char = 'b';
    printf("value.as_char = '%c'\n", value.as_char);
    printf("value.as_bits.first_bit = %d\n", value.as_bits.first_bit);
    puts("-- flip first bit --");
    value.as_bits.first_bit = 1;
    printf("value.as_bits.first_bit = %d\n", value.as_bits.first_bit);
    printf("value.as_char = '%c'\n", value.as_char);
}
