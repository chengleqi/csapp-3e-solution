#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void *calloc(size_t nmemb, size_t size)
{
    void *p;
    if (!(nmemb * size) || !(p = malloc(size * nmemb)))
        return NULL;
    else if (((size_t)(nmemb * size)) / size != nmemb)
    /* __builtin_umull_overflow() works too */
    {
        /* Thanks to zhzhwz who found a forget-to-free problem here.
           Maybe we should write a free_and_return_NULL block
           and goto it specifically.
        */
        fprintf(stderr, "size*nmemb overflow size_t.\n");
        free(p);
        return NULL;
    }
    else
    {
        memset(p, 0, size * nmemb);
        return p;
    }
}
