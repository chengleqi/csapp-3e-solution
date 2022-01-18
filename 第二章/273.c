#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);

int main(int argc, char const *argv[])
{
    printf("%d\n", saturating_add(123456, -54321));
    printf("%d\n", saturating_add(2147483647, 1));
    printf("%d\n", saturating_add(-2147483648, -1));
    return 0;
}

// 参考 https://blog.csdn.net/KQZXCMH/article/details/11649115
// 修正了李秋豪的错误

/* WARNING： The following code is buggy */
// int saturating_add(int x, int y)
// {
// 	unsigned sizeof_int = sizeof(int);
// 	unsigned w = sizeof_int << 8;
// 	int i = (x ^ y) >> (w-1);//+-:FFFFFFFF ++/--:00000000
// 	int j = ((x+y) ^ x) >> (w-1);//overflow:FFFFFFFF otherwise:00000000
// 	int k = x >> (w-1);//+:00000000 -:FFFFFFFF
// 	return (i & (x + y)) + (~i & (j & ( (~k & INT_MAX) + (k & INT_MIN) )));
// }

// 当x, y同号且没有溢出时, 返回值为0

int saturating_add(int x, int y)
{
    int w = sizeof(int) << 3;
    int ans = x + y;
    int is_overflow = ((x ^ ans) & (y ^ ans)) >> (w - 1);
    int x_sign = x >> (w - 1);
    return (~is_overflow & (x + y)) + (is_overflow & ((~x_sign & INT_MAX) + (x_sign & INT_MIN)));
}