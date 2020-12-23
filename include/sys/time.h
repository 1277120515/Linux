

struct  timeval
{
    long  tv_sec;       /*秒*/
    long  tv_usec;      /*微妙*/
};


struct  timezone
{
    int tz_minuteswest; /*和greenwich 时间差了多少分钟*/
    int tz_dsttime;     /*type of DST correction*/
};

typedef int  fd_set;


int   getitimer(int, struct itimerval *);
int   setitimer(int, const struct itimerval *, struct itimerval *);
int   gettimeofday(struct  timeval*tv, struct  timezone *tz);
int   utimes(const char *, const struct timeval[2]);



int select(int nfds, fd_set *readfds, fd_set *writefds,    fd_set *errorfds, struct timeval *timeout);
void FD_CLR(int fd, fd_set * fdset);
int FD_ISSET(int fd, fd_set * fdset);
void FD_SET(int fd, fd_set * fdset);
void FD_ZERO(fd_set * fdset);



// float getCurrentTime()
//{
//    struct timeval tv;
//    struct timezone tz;
//    gettimeofday(&tv, &tz);
//    printf("tv_sec:%d\n", tv.tv_sec);
//    printf("tv_usec:%d\n", tv.tv_usec);
//}