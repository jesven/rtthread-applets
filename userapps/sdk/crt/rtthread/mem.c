#include <sys/syscall.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    return (void *)syscall(_NRSYS_malloc, size);
}

void free(void *p)
{
    syscall(_NRSYS_free, p);
}

void *realloc(void *p, size_t newsize)
{
    return (void *)syscall(_NRSYS_realloc, p, newsize);
}
