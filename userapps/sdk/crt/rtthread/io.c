#include <sys/syscall.h>
#include <poll.h>

int open(const char *name, int flags, ...)
{
    return syscall(_NRSYS_open, name, flags);
}

int read(int fd, void *buf, int size)
{
    return syscall(_NRSYS_read, fd, buf, size);
}

int write(int fd, void *buf, int size)
{
    return syscall(_NRSYS_write, fd, buf, size);
}

int lseek(int fd, int pos, int w)
{
    return syscall(_NRSYS_lseek, fd, pos, w);
}

int close(int fd)
{
    return syscall(_NRSYS_close, fd);
}

int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    return syscall(_NRSYS_poll, fds, nfds, timeout);
}

void sys_log(const char *str, int size)
{
    syscall(0xff, str, size);
}

int ioctl(int fd, int cmd, void *args)
{
    return syscall(_NRSYS_ioctl, cmd, args);
}
