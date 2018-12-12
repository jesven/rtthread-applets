#include <sys/syscall.h>
#include <sys/time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    return syscall(_NRSYS_nanosleep, req, rem);
}

int usleep(unsigned useconds)
{
    struct timespec ts;

    ts.tv_sec = (long int)useconds / 1000000;
    ts.tv_nsec = ((long int)useconds % 1000000) * 1000;

	  return nanosleep(&ts, &ts);
}
