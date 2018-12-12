#ifndef __RTT_INET_H
#define __RTT_INET_H

#ifdef _BSD_SA_FAMILY_T_
typedef	_BSD_SA_FAMILY_T_	sa_family_t;
#undef _BSD_SA_FAMILY_T_
#else
typedef unsigned char sa_family_t;
#endif

/** 255.255.255.255 */
#define INADDR_NONE         0xffffffff
/** 127.0.0.1 */
#define INADDR_LOOPBACK     0x7f000001
/** 0.0.0.0 */
#define INADDR_ANY          0
/** 255.255.255.255 */
#define INADDR_BROADCAST    0xffffffff

/* Internet address (a structure for historical reasons). */
#ifndef	_STRUCT_IN_ADDR_DECLARED
struct in_addr 
{
	unsigned int s_addr;
};
#define	_STRUCT_IN_ADDR_DECLARED
#endif

/* Socket address, internet style. */
struct sockaddr_in 
{
	unsigned char sin_len;
	sa_family_t	sin_family;
	unsigned short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};


#define PP_HTONS(x) ((((x) & 0x00ffUL) << 8) | (((x) & 0xff00UL) >> 8))
#define PP_NTOHS(x) PP_HTONS(x)
#define PP_HTONL(x) ((((x) & 0x000000ffUL) << 24) | \
                     (((x) & 0x0000ff00UL) <<  8) | \
                     (((x) & 0x00ff0000UL) >>  8) | \
                     (((x) & 0xff000000UL) >> 24))
#define PP_NTOHL(x) PP_HTONL(x)

#define htons(x) (unsigned short)PP_HTONS(x)
#define ntohs(x) (unsigned short)PP_NTOHS(x)
#define htonl(x) (unsigned int)PP_HTONL(x)
#define ntohl(x) (unsigned int)PP_NTOHL(x)

#endif
