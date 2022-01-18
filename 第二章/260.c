#include <stdio.h>

typedef unsigned char *byte_pointer;

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(int argc, char *argv[])
{
    printf("%#.8X\n", replace_byte(0x12345678, 2, 0xab));
    printf("%#.8X\n", replace_byte(0x12345678, 0, 0xab));
    return 0;
}

//unsigned replace_byte(unsigned x, int i, unsigned char b) {
//    ((byte_pointer) &x)[i] = b;
//    return x;
//}

unsigned replace_byte(unsigned int x, int i, unsigned char b)
{
    int move = 8 * i;
    return x & ~(0xff << move) | b << move;
}