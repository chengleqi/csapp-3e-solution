#include <stdint.h>

int is_little_endian()
{
    int32_t val = 1;
    return ((unsigned char *)&val)[0];
}

int main(int argc, char *argv[])
{
    return is_little_endian();
}
