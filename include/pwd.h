#ifndef _PWD_H_
#define _PWD_H_

#include <sys/types.h>


struct passwd
{
    char    *pw_name;   //user's login name
    uid_t    pw_uid;   // numerical user ID
    gid_t    pw_gid;   // numerical group ID
    char    *pw_dir;   // initial working directory
    char    *pw_shell; // program to use as shell
};









struct passwd *getpwnam(const char *);
struct passwd *getpwuid(uid_t);
int            getpwnam_r(const char *, struct passwd *, char *,
    size_t, struct passwd **);
int            getpwuid_r(uid_t, struct passwd *, char *,
    size_t, struct passwd **);
void           endpwent(void);
struct passwd *getpwent(void);
void           setpwent(void);














#endif // !_PWD_H_
