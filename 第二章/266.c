// 详解见 https://blog.csdn.net/weixin_41256413/article/details/79937907
#include <stdio.h>

int leftmost_one(unsigned x);

int main(int argc, char *argv[])
{
    printf("odd_ones: %#.8X\n", leftmost_one((unsigned)0xFF00));
    printf("odd_ones: %#.8X\n", leftmost_one((unsigned)0x6600));
    return 0;
}

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}