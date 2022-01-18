#include <stdio.h>

int int_shifts_are_arithmetic();

int main(int argc, char *argv[])
{
    printf("int_shifts_are_arithmetic: %d\n", int_shifts_are_arithmetic());
    return 0;
}

int int_shifts_are_arithmetic()
{
    int x = -1;
    return !(~(x >> 1));
}