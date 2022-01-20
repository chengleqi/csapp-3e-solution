int mul3div4(int x)
{
    int k = 2;
    int bias = (1 << k) - 1;
    unsigned sizeof_int = sizeof(int);
    unsigned w = sizeof_int << 3;
    x = (x << 1) + x;
    int judge = x >> (w - 1); //-:FFFFFFFF +:00000000
    return (judge & ((x + bias) >> k)) + (~judge & (x >> k));
}
