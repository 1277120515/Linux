#ifndef _GRP_H_
#define _GRP_H_
#include <sys/types.h>



struct group
{
    char   *gr_name;    // the name of the group
    char * gr_passwd;
    gid_t   gr_gid;     // numerical group ID
    char  **gr_mem;     // pointer to a null - terminated array of character pointers to member names
};






struct group  *getgrgid(gid_t);
struct group  *getgrnam(const char *);
int            getgrgid_r(gid_t, struct group *, char *,
    size_t, struct group **);
int            getgrnam_r(const char *, struct group *, char *,
    size_t, struct group **);
struct group  *getgrent(void);
void           endgrent(void);
void           setgrent(void);





#endif // !_GRP_H_
