
#ifndef _TIME_H_
#define _TIME_H_

extern int       daylight;
extern long int  timezone;
extern char     *tzname[];

struct tm
{
    int    tm_sec;      //   seconds [0,61]
    int    tm_min;      //   minutes [0,59]
    int    tm_hour;     //  hour [0,23]
    int    tm_mday;     //  day of month [1,31]
    int    tm_mon;      //   month of year [0,11]
    int    tm_year;     //  years since 1900
    int    tm_wday;     //  day of week [0,6] (Sunday = 0)
    int    tm_yday;     //  day of year [0,365]
    int    tm_isdst;    // daylight savings flag
};
// The value of tm_isdst is positive if Daylight Saving Time is in effect, 
// 0 if Daylight Saving Time is not in effect, and negative if the information is not available.
// The range [0,61] for tm_sec allows for the occasional leap second or double leap second.
// tm_year is a signed value, therefore years before 1900 may be represented.


struct timespec
{
    time_t  tv_sec;//    seconds
    long    tv_nsec;//   nanoseconds
};


#define CLK_TCK 0
// Number of clock ticks per second returned by the times() function (LEGACY).
#define CLOCKS_PER_SEC 0
// A number used to convert the value returned by the clock() function into seconds.

// The following manifest constants are defined:
#define CLOCK_REALTIME 0
// The identifier of the systemwide realtime clock.
#define TIMER_ABSTIME 0
// Flag indicating time is absolute with respect to the clock associated with a timer.

char      *asctime(const struct tm *);
char      *asctime_r(const struct tm *, char *);
clock_t    clock(void);
int        clock_getres(clockid_t, struct timespec *);
int        clock_gettime(clockid_t, struct timespec *);
int        clock_settime(clockid_t, const struct timespec *);
char      *ctime(const time_t *);
char      *ctime_r(const time_t *, char *);
double     difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *gmtime_r(const time_t *, struct tm *);
struct tm *localtime(const time_t *);
struct tm *localtime_r(const time_t *, struct tm *);
time_t     mktime(struct tm *);
int        nanosleep(const struct timespec *, struct timespec *);
size_t     strftime(char *, size_t, const char *, const struct tm *);
char      *strptime(const char *, const char *, struct tm *);
time_t     time(time_t *);
int        timer_create(clockid_t, struct sigevent *, timer_t *);
int        timer_delete(timer_t);
int        timer_gettime(timer_t, struct itimerspec *);
int        timer_getoverrun(timer_t);
int        timer_settime(timer_t, int, const struct itimerspec *, struct itimerspec *);
void       tzset(void);



























#endif // !_TIME_H_




















