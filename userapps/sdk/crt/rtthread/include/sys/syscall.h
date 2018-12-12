#ifndef _SYS_SYSCALL_H
#define _SYS_SYSCALL_H


int syscall(int number, ...);

#define _NRSYS_exit         0x01
#define _NRSYS_read         0x02
#define _NRSYS_write        0x03
#define _NRSYS_lseek        0x04
#define _NRSYS_open         0x05
#define _NRSYS_close        0x06
#define _NRSYS_ioctl        0x07
#define _NRSYS_nanosleep    0x08
#define _NRSYS_fstat        0x10
#define _NRSYS_poll         0x11
#define _NRSYS_malloc        0x0d
#define _NRSYS_free          0x0e
#define _NRSYS_realloc       0x0f
#define _NRSYS_accept        0x12
#define _NRSYS_bind          0x13
#define _NRSYS_shutdown      0x14
#define _NRSYS_getpeername   0x15
#define _NRSYS_getsockname   0x16
#define _NRSYS_getsockopt    0x17
#define _NRSYS_setsockopt    0x18
#define _NRSYS_connect       0x19
#define _NRSYS_listen        0x1a
#define _NRSYS_recv          0x1b
#define _NRSYS_recvfrom      0x1c
#define _NRSYS_send          0x1d
#define _NRSYS_sendto        0x1e
#define _NRSYS_socket        0x1f

#endif
