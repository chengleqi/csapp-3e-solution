#include <stdio.h>

int tsub_ok(int x, int y);

int main(int argc, char const *argv[])
{
    printf("%d\n", tsub_ok(123456, 54321));
    printf("%d\n", tsub_ok(2147483647, -1));
    printf("%d\n", tsub_ok(-2147483648, 1));
    return 0;
}

int tsub_ok(int x, int y)
{
    unsigned w = (sizeof(int)) << 3;
    y = -y;
    int ans = x + y;
    return !(((x ^ ans) & (y ^ ans)) >> (w - 1));
}

// 以下为李秋豪的实现

// int tsub_ok(int x, int y)
// {
//     unsigned sizeof_int = sizeof(int);
//     unsigned w = sizeof_int << 8;
//     y = -y;

//     int i = (x ^ y) >> (w - 1);       //+-:FFFFFFFF ++/--:00000000
//     int j = ((x + y) ^ x) >> (w - 1); //overflow:FFFFFFFF otherwise:00000000
//     return i || ~j;
// }

// 个人认为不能用
// int j = ((x + y) ^ x) >> (w - 1); //overflow:FFFFFFFF otherwise:00000000
// 这条语句来判断是否溢出

// 例如
// printf("%#.8X\n", ((1 + -2) ^ 1) >> 31);
// 这条语句打印出0XFFFFFFFF, 并没有发生溢出
// 溢出的条件是 x > 0, y > 0, 但x <= 0时发生正溢出
// x < 0, y < 0, 但y >= 0时发生负溢出, 见csapp中文版P65
