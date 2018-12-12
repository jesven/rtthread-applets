#include <sys/socket.h>
#include <sys/syscall.h>

int	socket(int domain, int type, int protocol)
{
    return syscall(_NRSYS_socket, domain, type, protocol);
}

int bind(int s, const struct sockaddr *name, socklen_t namelen)
{
    return syscall(_NRSYS_bind, s, name, namelen);
}

int recvfrom(int s, void *mem, size_t len, int flags,
             struct sockaddr *from, socklen_t *fromlen)
{
    return syscall(_NRSYS_recvfrom,
			             s, mem, len, flags, from, fromlen);
}

int shutdown(int s, int how)
{
    return syscall(_NRSYS_shutdown, s, how);
}

int accept(int s, struct sockaddr *addr, socklen_t *addrlen)
{
    return syscall(_NRSYS_accept, s, addr, addrlen);
}

int listen(int s, int backlog)
{
    return syscall(_NRSYS_listen, s, backlog);
}

int recv(int s, void *mem, size_t len, int flags)
{
    return syscall(_NRSYS_recv, s, mem, len, flags);
}

int send(int s, const void *dataptr, size_t size, int flags)
{
    return syscall(_NRSYS_send, s, dataptr, size, flags);
}
