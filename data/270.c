// 详解见 https://blog.csdn.net/ZHgogogoha/article/details/107401960
#include <stdio.h>
#include <limits.h>

int fits_bits(int x, int n);

int main(int argc, char const *argv[])
{
    /*test short and 31bits*/
    printf("%d\n", fits_bits(-32768, 16));
    printf("%d\n", fits_bits(32767, 16));
    printf("%d\n", fits_bits(INT_MAX, 32));
    printf("%d\n", fits_bits(INT_MIN, 32));
    printf("%d\n", fits_bits(0, 16));
    printf("%d\n", fits_bits(0, 32));
    printf("%d\n", fits_bits(32768, 16));
    printf("%d\n", fits_bits(-32769, 16));
    printf("%d\n", fits_bits(INT_MIN, 31));
    printf("%d\n", fits_bits(INT_MAX, 31));
    return 0;
}

int fits_bits(int x, int n)
{
    unsigned sizeof_int = sizeof(int);
    unsigned w = sizeof_int << 3;
    int y = x << (w - n) >> (w - n);
    return y == x;
}
