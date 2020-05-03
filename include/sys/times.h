
#ifndef _TIMES_H_
#define _TIMES_H_

struct tms
{
    clock_t  tms_utime;  //  user CPU time
    clock_t  tms_stime;  //  system CPU time
    clock_t  tms_cutime;  // user CPU time of terminated child processes
    clock_t  tms_cstime;  // system CPU time of terminated child processes
};


clock_t times(struct tms *);




#endif // !_TIMES_H_




















