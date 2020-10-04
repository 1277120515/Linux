
#ifndef _WAIT_H_
#define _WAIT_H_

// The <sys/wait.h> header defines the following symbolic constants for use with waitpid():
#define WNOHANG
// Do not hang if no status is available, return immediately.
#define WUNTRACED
// Report status of stopped child process.
// and the following macros for analysis of process status values:

#define WEXITSTATUS(x) int(x)
// Return exit status.
#define WIFCONTINUED()
// True if child has been continued
#define WIFEXITED(x) int(x)
// True if child exited normally.
#define WIFSIGNALED(x) int(x)
// True if child exited due to uncaught signal.
#define WIFSTOPPED()
// True if child is currently stopped.
#define WSTOPSIG()
// Return signal number that caused process to stop.
#define WTERMSIG()
// Return signal number that caused process to terminate.
// The following symbolic constants are defined as possible values for the options argument to waitid():



#define WEXITED -1
// Wait for processes that have exited.
#define WSTOPPED -1
// Status will be returned for any child that has stopped upon receipt of a signal.
#define WCONTINUED
// Status will be returned for any child that was stopped and has been continued.
#define WNOHANG -1
// Return immediately if there are no children to wait for.
#define WNOWAIT -1
// Keep the process whose status is returned in infop in a waitable state.
// The type idtype_t is defined as an enumeration type whose possible values include at least the following:
enum
{
    P_ALL,
    P_PID,
    P_PGID
};

// The id_t type is defined as described in <sys/types.h>.
// The siginfo_t type is defined as described in <signal.h>.
// The rusage structure is defined as described in <sys/resource.h>.
// The pid_t type is defined as described in <sys/types.h>.
// Inclusion of the <sys/wait.h> header may also make visible all symbols from <signal.h> and <sys/resource.h>.
// The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.

typedef idtype_t;
typedef siginfo_t;


pid_t  wait(int *);
pid_t  wait3(int *, int, struct rusage *);
int    waitid(idtype_t, id_t, siginfo_t *, int);
pid_t  waitpid(pid_t, int *, int);




#endif // !_WAIT_H_



















