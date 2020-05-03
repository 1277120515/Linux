
#ifndef _NETDB_H_
#define _NETDB_H_


struct hostent
{
    char * h_name;
    char ** h_aliases;
    short h_addrtype;
    short h_length;
    char ** h_addr_list;
    char * h_addr;
// #define h_addr h_addr_list[0]
};
struct netent
{
    char  *n_name;      //Official, fully - qualified(including the domain) name of the host.
    char **n_aliases;   //A pointer to an array of pointers to alternative network names, terminated by a null pointer.
    int    n_addrtype;  //The address type of the network.
    uint32_t n_net;     //The network number, in host byte order.
};


struct protoent
{
    char  *p_name;      // Official name of the protocol.
    char **p_aliases;   // A pointer to an array of pointers to alternative protocol names, terminated by a null pointer.
    int    p_proto;     // The protocol number.
};


struct servent
{
    char  *s_name;      // Official name of the service.
    char **s_aliases;   // A pointer to an array of pointers to alternative service names, terminated by a null pointer.
    int    s_port;      // The port number at which the service resides, in network byte order.
    char  *s_proto;     // The name of the protocol to use when contacting the service.
};

extern int h_errno;

#define HOST_NOT_FOUND 0
#define NO_DATA 0
#define NO_RECOVERY 0
#define TRY_AGAIN 0




void             endhostent(void);
void             endnetent(void);
void             endprotoent(void);
void             endservent(void);
struct hostent  *gethostbyaddr(const void *addr, size_t len, int type);
struct hostent  *gethostbyname(const char *name);
struct hostent  *gethostent(void);
struct netent   *getnetbyaddr(uint32_t net, int type);
struct netent   *getnetbyname(const char *name);
struct netent   *getnetent(void);
struct protoent *getprotobyname(const char *name);
struct protoent *getprotobynumber(int proto);
struct protoent *getprotoent(void);
struct servent  *getservbyname(const char *name, const char *proto);
struct servent  *getservbyport(int port, const char *proto);
struct servent  *getservent(void);
void             sethostent(int stayopen);
void             setnetent(int stayopen);
void             setprotoent(int stayopen);
void             setservent(int stayopen);



// The gethostent(), gethostbyaddr(), and gethostbyname() functions each return a pointer to a hostent structure, the members of which contain the fields of an entry in the network host database.
// The gethostent() function
// reads the next entry of the database, opening a connection to the database if necessary.

// The gethostbyaddr() function
// searches the database and finds an entry which matches the address family specified by the type argument and which matches the address pointed to by the addr argument, opening a connection to the database if necessary. The addr argument is a pointer to the binary-format (that is, not null-terminated) address in network byte order, whose length is specified by the len argument. The datatype of the address depends on the address family. For an address of type AF_INET, this is an in_addr structure, defined in <netinet/in.h>.

// The gethostbyname() function
// searches the database and finds an entry which matches the host name specified by the name argument, opening a connection to the database if necessary. If name is an alias for a valid host name, the function returns information about the host name to which the alias refers, and name is included in the list of aliases returned.

// The sethostent() function
// opens a connection to the network host database, and sets the position of the next entry to the first entry. If the stayopen argument is non-zero, the connection to the host database will not be closed after each call to gethostent() (either directly, or indirectly through one of the other gethost*() functions).

// The endhostent() function
// closes the connection to the database.




#endif // !_NETDB_H_


/*

主机名转IP
struct hostent * host;
host = gethostbyname(argv[2]);
assert(host);
char * remote_ip = inet_ntoa(*((struct in_addr *)host->h_addr));

*/














