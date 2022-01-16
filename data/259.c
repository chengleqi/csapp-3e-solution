#include <stdio.h>

// typedef unsigned char *byte_pointer;

// void show_int(int32_t x);

// void show_bytes(byte_pointer start, size_t len);

// int main(int argc, char *argv[])
// {
//     int32_t x = 0x89abcdef;
//     int32_t y = 0x76543210;
//     int32_t word;
//     ((byte_pointer)&word)[0] = ((byte_pointer)&x)[0];
//     for (int i = 1; i < sizeof(int32_t); ++i)
//     {
//         ((byte_pointer)&word)[i] = ((byte_pointer)&y)[i];
//     }
//     show_int(word);
//     return 0;
// }

// void show_int(int32_t x)
// {
//     show_bytes((byte_pointer)&x, sizeof(int32_t));
// }

// void show_bytes(byte_pointer start, size_t len)
// {
//     size_t i;
//     for (i = 0; i < len; i++)
//         printf(" %.2x", start[i]); //line:data:show_bytes_printf
//     printf("\n");
// }

int main(int argc, char const *argv[])
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    printf("0x%.8X\n", x & 0xff | y & ~0xff);
    return 0;
}
