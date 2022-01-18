#include <stdio.h>

int any_odd_one(unsigned x);

int main(int argc, char *argv[])
{
    printf("any_odd_one: %d\n", any_odd_one((unsigned)5));
    printf("any_odd_one: %d\n", any_odd_one((unsigned)0xa));
    return 0;
}

// 该题目要求，只要奇数位有1，就返回1，否则返回0
int any_odd_one(unsigned x)
{
    return (x & 0x55555555) != 0;
}