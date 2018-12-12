#include <sys/syscall.h>

void _exit(int s)
{
    syscall(_NRSYS_exit, s);
}

void exit(int code)
{
    syscall(_NRSYS_exit, code);
}
