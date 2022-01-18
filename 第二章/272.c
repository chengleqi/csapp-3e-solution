/*
A:

sizeof返回的类型为size_t：

According to the 1999 ISO C standard (C99), size_t is an unsigned integer type of at least 16 bit (see sections 7.17 and 7.18.3).

size_tis an unsigned data type defined by several C/C++ standards, e.g. the C99 ISO/IEC 9899 standard, that is defined in stddef.h.1 It can be further imported by inclusion ofstdlib.h as this file internally sub includes stddef.h.

所以maxbytes-sizeof(val)将一直转化为无符号数并永远大于等于零。
*/

// B:

void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes < 0)
        return;
    if (maxbytes >= sizeof(val))
        memcpy(buf, (void *)&val, sizeof(val));
}