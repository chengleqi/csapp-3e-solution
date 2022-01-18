// 详解见 https://blog.csdn.net/weixin_41256413/article/details/79937907
#include <stdio.h>

int odd_ones(unsigned x);

int main(int argc, char *argv[])
{
    printf("odd_ones: %d\n", odd_ones((unsigned)0xFF01FF00));
    printf("odd_ones: %d\n", odd_ones((unsigned)0xFF00FF00));
    return 0;
}

int odd_ones(unsigned x)
{
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;
    return x & 1;
}