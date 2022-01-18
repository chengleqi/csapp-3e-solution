#include <stdio.h>

int int_size_is_32();

int main(int argc, char const *argv[])
{
    printf("%d\n", int_size_is_32());
    return 0;
}

int int_size_is_32()
{
    int set_msb = 1 << 15;
    set_msb <<= 15;
    set_msb <<= 1;
    int beyond_msb = set_msb;
    beyond_msb <<= 1;
    return set_msb && !beyond_msb;
}