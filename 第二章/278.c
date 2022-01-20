#include <stdio.h>

int divide_power2(int x, int k);

int main(int argc, char const *argv[])
{
    printf("%d\n", divide_power2(1024, 2));
    printf("%d\n", divide_power2(5, 2));
    printf("%d\n", divide_power2(-1024, 2));
    printf("%d\n", divide_power2(-5, 2));
    return 0;
}

int divide_power2(int x, int k)
{
    int bias = (1 << k) - 1;
    unsigned sizeof_int = sizeof(int);
    unsigned w = sizeof_int << 3;
    int judge = x >> (w - 1); //-:FFFFFFFF +:00000000
    return (judge & ((x + bias) >> k)) + (~judge & (x >> k));
}