#ifndef _NET_INET_IN_H_
#define _NET_INET_IN_H_



//
// When header file <netinet/in.h> is included, the following types are defined through typedef.
// in_port_t
// An unsigned integral type of exactly 16 bits.
typedef unsigned short in_port_t;

// in_addr_t
// An unsigned integral type of exactly 32 bits.
typedef unsigned int in_addr_t;

// The <netinet/in.h> header defines the in_addr structure that includes at least the following member:
// in_addr_t      s_addr
struct in_addr
{
    in_addr_t s_addr;
};




// The <netinet/in.h> header defines the sockaddr_in structure that includes at least the following member:
struct sockaddr_in
{
    sa_family_t    sin_family;
    in_port_t      sin_port;
    struct in_addr sin_addr;
    unsigned char  sin_zero[8];
};


// The sockaddr_in structure is used to store addresses for the Internet protocol family. 
// Values of this type must be cast to struct sockaddr for use with the socket interfaces defined in this document.
// The <netinet/in.h> header defines the type sa_family_t as described in <sys/socket.h>.

// The <netinet/in.h> header defines the following macros for use as values of the level argument of getsockopt() and setsockopt():

#define IPPROTO_IP 0
// Dummy for IP.
#define IPPROTO_ICMP 0
// Control message protocol.
#define IPPROTO_TCP 0
// TCP.
#define IPPROTO_UDP 0
// User datagram protocol.
// The <netinet/in.h> header defines the following macros for use as destination addresses for connect(), sendmsg() and sendto():

#define INADDR_ANY 0
// Local host address.
#define INADDR_BROADCAST 0
// Broadcast address.







#endif