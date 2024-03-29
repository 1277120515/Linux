#ifndef _UNISTD_H_
#define _UNISTD_H_



extern char   *optarg;
extern int    optind, opterr, optopt;

// Constants for Functions

// The following symbolic constant is defined:
#define NULL 0
// Null pointer
// The following symbolic constants are defined for the access() function:

#define R_OK 0
// Test for read permission.
#define W_OK 0
// Test for write permission.
#define X_OK 0
// Test for execute (search) permission.
#define F_OK 0
// Test for existence of file.

#define SEEK_SET	0	
#define SEEK_CUR	1
#define SEEK_END	2

 
// The following symbolic constants are defined for file streams:

#define STDIN_FILENO 0
// File number of stdin. It is 0.
#define STDOUT_FILENO 1
// File number of stdout. It is 1.
#define STDERR_FILENO 2
// File number of stderr. It is 2

 
// The size_t, ssize_t, uid_t, gid_t, off_t and pid_t types are defined as described in <sys/types.h>.
// The useconds_t type is defined as described in <sys/types.h>.
// The intptr_t type is defined as described in <inttypes.h>

typedef int uid_t;
typedef int gid_t;
typedef int off_t;
// 由此我们终于找到了pid_t的真实定义：实际他就是  int  类型的。
typedef int pid_t;
typedef int useconds_t;

 



int          access(const char *, int);
unsigned int alarm(unsigned int);
int          brk(void *);
int          chdir(const char *);
int          chroot(const char *);  
int          chown(const char *, uid_t, gid_t);
int          close(int);
size_t       confstr(int, char *, size_t);
char        *crypt(const char *, const char *);
char        *ctermid(char *);
char        *cuserid(char *s); 
int          dup(int);

// 描述符 -- 指针
//newfd的指针，指向oldfd，返回oldfd的描述符
int          dup2(int oldfd, int newfd);

void         encrypt(char[64], int);


// 1 .带 l 的exec函数：execl,execlp,execle，表示后边的参数以可变参数的形式给出且都以一个空指针结束。
// 2. 带 v 的exec函数：execv,execvp表示命令所需的参数以char *arg[]形式给出且arg最后一个元素必须

// 3. 带 p 的exec函数：execlp,execvp，表示第一个参数path不用输入完整路径，只有给出命令名即可，它会在环境变量PATH当中查找命令
// 4. 不带 p 的exec函数：execlp,execvp，表示用全路径

// 5. 带 e 的exec函数：execle表示，将环境变量传递给需要替换的进程

// last parameter is null
int          execl(const char * path, const char *, ...);

// last parameter is null
int          execle(const char * path, const char *, ...);

// last parameter is null
int          execlp(const char * path, const char *, ...);

// null terminal array
int          execv(const char * path, char * args []);

// null terminal array
int          execve(const char * path, char *const[], char * args[]);

// null terminal array
int          execvp(const char * path, char * args[]);

int         execvpe(const char * path, char * const argv[], char * const envp[]);



void        _exit(int);
int          fchown(int, uid_t, gid_t);
int          fchdir(int);
int          fdatasync(int);
pid_t        fork(void);
long int     fpathconf(int, int);
int          fsync(int);
int          ftruncate(int, off_t);
char        *getcwd(char *, size_t);
int          getdtablesize(void); 
gid_t        getegid(void);
uid_t        geteuid(void);
gid_t        getgid(void);
int          getgroups(int, gid_t[]);
long         gethostid(void);
char        *getlogin(void);
int          getlogin_r(char *, size_t);
int          getopt(int, char * const[], const char *);
int          getpagesize(void); 
char        *getpass(const char *); 
pid_t        getpgid(pid_t);
pid_t        getpgrp(void);
pid_t        getpid(void);
pid_t        getppid(void);
pid_t        getsid(pid_t);
uid_t        getuid(void);
char        *getwd(char *);
int          isatty(int);
int          lchown(const char *, uid_t, gid_t);
int          link(const char *, const char *);
int          lockf(int, int, off_t);
off_t        lseek(int, off_t, int);
int          nice(int);
long int     pathconf(const char *, int);
int          pause(void);

// fd[0]: 外部从中读取
// fd[1]: 外部向里面写入
int          pipe(int fd[2]);
ssize_t      pread(int, void *, size_t, off_t);
int          pthread_atfork(void(*)(void), void(*)(void),
    void(*)(void));
ssize_t      pwrite(int, const void *, size_t, off_t);
ssize_t      read(int, void *, size_t);
int          readlink(const char *, char *, size_t);
int          rmdir(const char *);
void        *sbrk(intptr_t);
int          setgid(gid_t);
int          setpgid(pid_t, pid_t);
pid_t        setpgrp(void);
int          setregid(gid_t, gid_t);
int          setreuid(uid_t, uid_t);
pid_t        setsid(void);
int          setuid(uid_t);
unsigned int sleep(unsigned int);
void         swab(const void *, void *, ssize_t);
int          symlink(const char *, const char *);
void         sync(void);
long int     sysconf(int);
pid_t        tcgetpgrp(int);
int          tcsetpgrp(int, pid_t);
int          truncate(const char *, off_t);
char        *ttyname(int);
int          ttyname_r(int, char *, size_t);
useconds_t   ualarm(useconds_t, useconds_t);
int          unlink(const char *);
int          usleep(useconds_t);
pid_t        vfork(void);
ssize_t      write(int, const void *, size_t);



// The gethostname() function returns the standard host name for the current machine. The namelen argument specifies the size of the array pointed to by the name argument. The returned name is null-terminated, except that if namelen is an insufficient length to hold the host name, then the returned name is truncated and it is unspecified whether the returned name is null-terminated.
// Host names are limited to 255 bytes.
int gethostname(char *name, size_t namelen);

/**




*/










































#endif

//#include <getopt.h>
//
//typedef unsigned int size_t;
//typedef int ssize_t;
//typedef int __pid_t;
//typedef __pid_t pid_t;





