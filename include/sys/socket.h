#ifndef _SOCKET_H_
#define _SOCKET_H_


typedef int ssize_t;

// <sys/socket.h> makes available a type, socklen_t, which is an unsigned opaque integral type of length of at least 32 bits. 
// To forestall portability problems, it is recommended that applications should not use values larger than 232 - 1.
typedef unsigned int socklen_t;

// The <sys/socket.h> header defines the unsigned integral type sa_family_t.
typedef unsigned int sa_family_t;
// The <sys/socket.h> header defines the sockaddr structure that includes at least the following members:

struct sockaddr
{
    sa_family_t   sa_family;//     address family
    char          sa_data[];//     socket address (variable-length data)
};




// The <sys/socket.h> header defines the following macros, with distinct integral values:
#define SOCK_DGRAM 0
// Datagram socket
#define SOCK_STREAM 0
// Byte-stream socket
#define SOCK_SEQPACKET 0
// Sequenced-packet socket
// The <sys/socket.h> header defines the following macro for use as the level argument of setsockopt() and getsockopt().

#define SOL_SOCKET 0
// Options to be accessed at socket level, not protocol level.
// The <sys/socket.h> header defines the following macros, with distinct integral values, for use as the option_name argument in getsockopt() or setsockopt() calls:

#define SO_ACCEPTCONN 0
// Socket is accepting connections.
#define SO_BROADCAST 0
// Transmission of broadcast messages is supported.
#define SO_DEBUG 0
// Debugging information is being recorded.
#define SO_DONTROUTE 0
// bypass normal routing
#define SO_ERROR 0
// Socket error status.
#define SO_KEEPALIVE 0
// Connections are kept alive with periodic messages.
#define SO_LINGER 0
// Socket lingers on close.
#define SO_OOBINLINE 0
// Out-of-band data is transmitted in line.
#define SO_RCVBUF 0
// Receive buffer size.
#define SO_RCVLOWAT 0
// receive "low water mark"
#define SO_RCVTIMEO 0
// receive timeout
#define SO_REUSEADDR 0
// Reuse of local addresses is supported.
#define SO_SNDBUF 0
// Send buffer size.
#define SO_SNDLOWAT 0
// send "low water mark"
#define SO_SNDTIMEO 0
// send timeout
#define SO_TYPE 0
// Socket type.




// The <sys/socket.h> header defines the following macros, with distinct integral values, for use as the valid values for the msg_flags field in the msghdr structure, or the flags parameter in recvfrom(), recvmsg(), sendto() or sendmsg() calls:

#define MSG_CTRUNC 0
// Control data truncated.
#define MSG_DONTROUTE 0
// Send without using routing tables.
#define MSG_EOR 0
// Terminates a record (if supported by the protocol).
#define MSG_OOB 0
// Out-of-band data.
#define MSG_PEEK 0
// Leave received data in queue.
#define MSG_TRUNC 0
// Normal data truncated.
#define MSG_WAITALL 0
// Wait for complete message.

// The <sys/socket.h> header defines the following macros, with distinct integral values:

#define AF_UNIX 0
// UNIX domain sockets
#define AF_UNSPEC 0
// Unspecified
#define AF_INET 0
// Internet domain sockets


// The <sys/socket.h> header defines the following macros, with distinct integral values:

#define SHUT_RD 0
// Disables further receive operations.

#define SHUT_WR 0
// Disables further send operations.

#define SHUT_RDWR 0
// Disables further send and receive operations.

// The following are declared as functions, and may also be defined as macros :


int     accept(int socket, struct sockaddr *address, socklen_t *address_len);
int     bind(int socket, const struct sockaddr *address, socklen_t address_len);
int     connect(int socket, const struct sockaddr *address, socklen_t address_len);
int     getpeername(int socket, struct sockaddr *address, socklen_t *address_len);
int     getsockname(int socket, struct sockaddr *address, socklen_t *address_len);
int     getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len);
int     listen(int socket, int backlog);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t recvfrom(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len);
ssize_t recvmsg(int socket, struct msghdr *message, int flags);
ssize_t send(int socket, const void *message, size_t length, int flags);
ssize_t sendmsg(int socket, const struct msghdr *message, int flags);
ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
int     setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int     shutdown(int socket, int how);
int     socket(int domain, int type, int protocol);
int     socketpair(int domain, int type, int protocol, int socket_vector[2]);

#endif


/*
// 接收端
void * thread_fun(void * arg)
{
int err;
int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(5777);// 绑定本机的端口5577
// addr.sin_addr.s_addr = inet_addr("0.0.0.0");// 绑定本机所有的IP
addr.sin_addr.s_addr = INADDR_ANY;// 绑定本机所有的IP
err = bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
if (err != 0)
{
printf("Already Bind\n");
exit(0);
}
struct sockaddr_in remoteAddr;
socklen_t addrLen = sizeof(struct sockaddr_in);

char buf[100];
while (1)
{
ssize_t sz = recvfrom(sockfd, buf, 100, 0, (struct sockaddr*)&remoteAddr, &addrLen);
printf("Recv(%d): %s\n", ntohs(remoteAddr.sin_port), buf);
}
}



// 发送端
int main(int argc, char *argv[])
{
pthread_t tid;
pthread_create(&tid, NULL, thread_fun, NULL);

int err;
int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in remoteAddr;
remoteAddr.sin_family = AF_INET;
remoteAddr.sin_port = htons(5777);
remoteAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

socklen_t addrLen = sizeof(struct sockaddr_in);

char buf[100];
while (1)
{
scanf("%s", buf);

// 未绑定端口，则用可用端口，发送消息
sendto(sockfd, buf, strlen(buf) + 1, 0, (struct sockaddr*)&remoteAddr, addrLen);
}
}

// TCP聊天工具
nc -l 1234 > test.txt
nc 192.168.2.34 < test.txt
// UDP聊天工具
nc -u -l 1234 > test.txt
nc -u 192.168.2.34 < test.txt
*/