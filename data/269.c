#include <stdio.h>

unsigned rotate_left(unsigned x, int n);

int main(int argc, char const *argv[])
{
    unsigned x = 0x12345678;
    printf("%#.8x\n", rotate_left(x, 0));
    printf("%#.8x\n", rotate_left(x, 4));
    printf("%#.8x\n", rotate_left(x, 20));
    return 0;
}

unsigned rotate_left(unsigned x, int n)
{
    unsigned sizeof_unsigned = sizeof(unsigned);
    unsigned w = sizeof_unsigned << 3;
    unsigned mask = ((1 << n) - 1) << (w - n);
    unsigned cache = (mask & x) >> (w - n);
    x <<= n;
    return x | cache;
}
