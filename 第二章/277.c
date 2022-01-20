#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned sizeof_int = sizeof(int);
    unsigned w = sizeof_int << 3;
    int x = 1;
    printf("%d\n", (x << 4) + x);        //k=17
    printf("%d\n", x - (x << 3));        //k=-7
    printf("%d\n", (x << 6) - (x << 2)); //k=60
    printf("%d\n", (x << 4) - (x << 7)); //k=-112
    return 0;
}
