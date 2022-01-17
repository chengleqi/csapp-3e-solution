#include <stdio.h>
#include <limits.h>

unsigned srl(unsigned x, int k);

int sra(int x, int k);

int main(int argc, char *argv[])
{
    printf("%#.8x\n", srl(0x80000000, 8));
    printf("%#.8x\n", sra(0x80000000, 8));
    return 0;
}

unsigned srl(unsigned int x, int k)
{
    unsigned xsra = (int)x >> k;
    return xsra & (INT_MAX >> (k - 1));
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;
    /*这个题目的关键点是判断符号位是否为1，通过test &= xsrl，test为零如果符号位为0，否则test不变（处于符号位位置*/
    unsigned w = sizeof(int) << 3;
    int test = 1 << (w - 1 - k);
    test &= xsrl;
    int mask = ~(test - 1);
    /*test为零时，~(test - 1)为全零，不会改变xsrl*/
    return mask | xsrl;
}