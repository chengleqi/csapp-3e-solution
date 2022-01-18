/*
A:
当取出的字节为负数时，由于原操作“粗暴”的将高位置零，会返回一个错误的正值。
*/

// B:
#include <stdio.h>

typedef unsigned packed_t;

int xbytte(packed_t word, int bytenum);

int main(int argc, char const *argv[])
{
    packed_t word = 0x8008FF00;
    printf("%d\n", xbytte(word, 0));
    printf("%d\n", xbytte(word, 1));
    printf("%d\n", xbytte(word, 2));
    printf("%d\n", xbytte(word, 3));
    return 0;
}

int xbytte(packed_t word, int bytenum)
{
    unsigned left_move = (3 - bytenum) << 3;
    unsigned right_move = (3) << 3;
    return (int)word << left_move >> right_move;
}
