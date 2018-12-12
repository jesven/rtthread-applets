#ifndef _POLL_H
#define _POLL_H

#define POLLIN          (0x01)
#define POLLRDNORM      (0x01)
#define POLLRDBAND      (0x01)
#define POLLPRI         (0x01)

#define POLLOUT         (0x02)
#define POLLWRNORM      (0x02)
#define POLLWRBAND      (0x02)

#define POLLERR         (0x04)
#define POLLHUP         (0x08)
#define POLLNVAL        (0x10)

typedef unsigned int nfds_t;

struct pollfd
{
    int fd;
    short events;
    short revents;
};

int	poll(struct pollfd *fds, nfds_t nfds, int timeout);

#endif
