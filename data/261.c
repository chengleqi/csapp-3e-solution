#include <stdio.h>

int main(int argc, char *argv[])
{
    int x, y;
    int sizeof_int = sizeof(int);

    /*Condition A*/
    x = ~0;
    y = 0x000000ff;
    printf("%d\t%d\n", !(~x), !(~y));

    x = 0;
    y = ~0;
    printf("%d\t%d\n", !x, !y);

    x = -1;
    y = 0xfffffff0;
    printf("%d\t%d\n", !((x ^ 0xFF) << ((sizeof_int - 1) << 3)), !((y ^ 0xFF) << ((sizeof_int - 1) << 3)));

    x = 0x00ffffff;
    y = 0x0fffffff;
    printf("%d\t%d\n", !(x >> ((sizeof_int - 1) << 3)), !(y >> ((sizeof_int - 1) << 3)));

    return 0;
}