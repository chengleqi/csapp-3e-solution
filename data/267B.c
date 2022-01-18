#include <stdio.h>

/*
"If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior is undefined"
*/

int int_size_is_32();

int main(int argc, char const *argv[])
{
    printf("%d\n", int_size_is_32());
    return 0;
}

int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb;
    beyond_msb <<= 1;
    return set_msb && !beyond_msb;
}