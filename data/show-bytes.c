/* $begin show-bytes */
#include <stdio.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]); //line:data:show_bytes_printf
    printf("\n");
}

void show_chars(const char *x)
{
    show_bytes((byte_pointer)x, strlen(x));
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *)); //line:data:show_bytes_amp3
}
/* $end show-bytes */

/* $begin test-show-bytes */
void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

    const char *s = "abcdef";
    show_chars(s);

    short x = 12345;
    short mx = -x;
    unsigned short y = 53191;
    show_bytes((byte_pointer)&x, sizeof(short));          //39 30
    show_bytes((byte_pointer)&mx, sizeof(short));         //c7 cf
    show_bytes((byte_pointer)&y, sizeof(unsigned short)); //c7 cf

    short int v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);

    unsigned u = 4294967295u; /*UMax*/
    int tu = (int)u;
    printf("u = %u, tu = %d\n", u, tu);

    short sx = -12345;
    unsigned short usx = sx;
    int ix = sx;
    unsigned uix = usx;

    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));
    printf("usx = %d:\t", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));
    printf("ix = %d:\t", ix);
    show_bytes((byte_pointer)&ix, sizeof(int));
    printf("uix = %d:\t", uix);
    show_bytes((byte_pointer)&uix, sizeof(unsigned));
}
/* $end test-show-bytes */

int main(int argc, char *argv[])
{
    int val = 12345;
    printf("calling test_show_bytes\n");
    test_show_bytes(val);

    return 0;
}
