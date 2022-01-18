#include <stdio.h>

int lower_one_mask(int n);

int main(int argc, char *argv[])
{
    printf("%#.8X\n", lower_one_mask(6));
    printf("%#.8X\n", lower_one_mask(17));
    return 0;
}

int lower_one_mask(int n)
{
    unsigned x = -1;
    x >>= ((sizeof(int) << 3) - n);
    return x;
}