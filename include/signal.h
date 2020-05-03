

#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <pthread.h>

// The <signal.h> header defines the following symbolic constants, each of which expands to a distinct constant expression of the type:

// void (*)(int)

// whose value matches no declarable function.

#define SIG_DFL
// Request for default signal handling.
#define SIG_ERR
// Return value from signal() in case of error.
#define SIG_HOLD
// Request that signal be held.
#define SIG_IGN
// Request that signal be ignored.

typedef int sig_atomic_t;
// Integral type of an object that can be accessed as an atomic entity, even in the presence of asynchronous interrupts
typedef int sigset_t;
// Integral or structure type of an object used to represent sets of signals.


typedef struct stack_t
{
    void     *ss_sp; //      stack base or pointer
    size_t    ss_size; //     stack size
    int       ss_flags; //     flags
}stack_t;

struct sigstack
{
    int       ss_onstack; //  non-zero when signal stack is in use
    void     *ss_sp; //       signal stack pointer
};

typedef struct siginfo_t
{
    int           si_signo; //signal number
    int           si_errno; //if non-zero, an errno value associated with this signal, as defined in <errno.h>
    int           si_code; //signal code
    pid_t         si_pid; //sending process ID
    uid_t         si_uid; //real user ID of sending process
    void         *si_addr; //address of faulting instruction
    int           si_status; //exit value or signal
    long          si_band; //band event for SIGPOLL
    union sigval  si_value; //signal value
}siginfo_t;


union sigval
{
    int    sival_int; //   integer signal value
    void*  sival_ptr; //   pointer signal value
};

typedef void(*sigev_notify_function_t)(union sigval);
struct sigevent
{
    int                      sigev_notify; //            notification type
    int                      sigev_signo; //             signal number
    union sigval             sigev_value; //             signal value
    sigev_notify_function_t  sigev_notify_function; //   notification function
    pthread_attr_t* sigev_notify_attributes; // notification attributes
};

// The following values of sigev_notify are defined :

#define SIGEV_NONE
// No asynchronous notification will be delivered when the event of interest occurs.
#define SIGEV_SIGNAL
// A queued signal, with an application-defined value, will be generated when the event of interest occurs.
#define SIGEV_THREAD
// A notification function will be called to perform notification.

#define SIGRTMIN 
#define SIGRTMAX
// The range SIGRTMIN through SIGRTMAX inclusive includes at least RTSIG_MAX signal numbers.


//==============================================
//Signal	Default Action	Description
//----------------------------------------------
//SIGABRT	ii	Process abort signal.
//SIGALRM	i	Alarm clock.
//SIGFPE	ii	Erroneous arithmetic operation.
//SIGHUP	i	Hangup.
//SIGILL	ii	Illegal instruction.
//SIGINT	i	Terminal interrupt signal.
//SIGKILL	i	Kill (cannot be caught or ignored).
//SIGPIPE	i	Write on a pipe with no one to read it.
//SIGQUIT	ii	Terminal quit signal.
//SIGSEGV	ii	Invalid memory reference.
//SIGTERM	i	Termination signal.
//SIGUSR1	i	User-defined signal 1.
//SIGUSR2	i	User-defined signal 2.
//SIGCHLD	iii	Child process terminated or stopped.
//SIGCONT	v	Continue executing, if stopped.
//SIGSTOP	iv	Stop executing (cannot be caught or ignored).
//SIGTSTP	iv	Terminal stop signal.
//SIGTTIN	iv	Background process attempting read.
//SIGTTOU	iv	Background process attempting write.
//SIGBUS	ii	Access to an undefined portion of a memory object.
//SIGPOLL	i	Pollable event.
//SIGPROF	i	Profiling timer expired.
//SIGSYS	ii	Bad system call.
//SIGTRAP	ii	Trace/breakpoint trap.
//SIGURG	iii	High bandwidth data is available at a socket.
//SIGVTALRM	i	Virtual timer expired.
//SIGXCPU	ii	CPU time limit exceeded.
//SIGXFSZ	ii	File size limit exceeded.
//==============================================
//
//The default actions are as follows:
//
//i
//Abnormal termination of the process. The process is terminated with all the consequences of _exit() except that the status made available to wait() and waitpid() indicates abnormal termination by the specified signal.
//ii
//Abnormal termination of the process. Additionally, implementation-dependent abnormal termination actions, such as creation of a core file, may occur.
//iii
//Ignore the signal.
//iv
//Stop the process.
//v
//Continue the process, if it is stopped; otherwise ignore the signal.

#define SIGABRT 6	// ii	Process abort signal.
#define SIGALRM 14	    // i	Alarm clock.
#define SIGFPE 8	// ii	Erroneous arithmetic operation.
#define SIGHUP 1	// i	Hangup.
#define SIGILL 4	// ii	Illegal instruction.
#define SIGINT 2	// i	Terminal interrupt signal. Ctrl+C
#define SIGKILL	    // i	Kill (cannot be caught or ignored).
#define SIGPIPE 13	// i	Write on a pipe with no one to read it.
#define SIGQUIT 3	// ii	Terminal quit signal. Ctrl+\  (反斜线)  
#define SIGSEGV 11	// ii	Invalid memory reference.
#define SIGTERM 15	// i	Termination signal.
#define SIGUSR1	    // i	User-defined signal 1.
#define SIGUSR2	    // i	User-defined signal 2.
#define SIGCHLD	    // iii	Child process terminated or stopped.
#define SIGCONT	    // v	Continue executing, if stopped.
#define SIGSTOP 17	// iv	Stop executing (cannot be caught or ignored).
#define SIGTSTP	    // iv	Terminal stop signal.
#define SIGTTIN	    // iv	Background process attempting read.
#define SIGTTOU	    // iv	Background process attempting write.
#define SIGBUS	    // ii	Access to an undefined portion of a memory object.
#define SIGPOLL	    // i	Pollable event.
#define SIGPROF	    // i	Profiling timer expired.
#define SIGSYS	    // ii	Bad system call.
#define SIGTRAP 	// ii	Trace/breakpoint trap.
#define SIGURG 16	// iii	High bandwidth data is available at a socket.
#define SIGVTALRM	// i	Virtual timer expired.
#define SIGXCPU	    // ii	CPU time limit exceeded.
#define SIGXFSZ	    // ii	File size limit exceeded.








typedef void(*sa_sigaction_fun_t)(int, struct siginfo_t *, void *);
struct sigaction
{
    void(*sa_handler)(int);// what to do on receipt of signal
    sigset_t   sa_mask;//          set of signals to be blocked during execution of the signal handling function
    int        sa_flags;//          special flags
    sa_sigaction_fun_t sa_sigaction;// pointer to signal handler function or one of the macros SIG_IGN or SIG_DFL
};


// The following are declared as constants:

#define SA_NOCLDSTOP
// Do not generate SIGCHLD when children stop.
#define SIG_BLOCK
// The resulting set is the union of the current set and the signal set pointed to by the argument set.
#define SIG_UNBLOCK
// The resulting set is the intersection of the current set and the complement of the signal set pointed to by the argument set.
#define SIG_SETMASK
// The resulting set is the signal set pointed to by the argument set.
#define SA_ONSTACK
// Causes signal delivery to occur on an alternate stack.
#define SA_RESETHAND
// Causes signal dispositions to be set to SIG_DFL on entry to signal handlers.
#define SA_RESTART
// Causes certain functions to become restartable.
#define SA_SIGINFO
// Causes extra information to be passed to signal handlers at the time of receipt of a signal.
#define SA_NOCLDWAIT
// Causes implementations not to create zombie processes on child death.
#define SA_NODEFER
// Causes signal not to be automatically blocked on entry to signal handler.
#define SS_ONSTACK
// Process is executing on an alternate signal stack.
#define SS_DISABLE
// Alternate signal stack is disabled.
#define MINSIGSTKSZ
// Minimum stack size for a signal handler.
#define SIGSTKSZ
// Default size in bytes for the alternate signal stack.






// The macros specified in the Code column of the following table are defined 
// for use as values of si_code that are signal-specific reasons why the signal 
// was generated.

//==================================================================================
//Signal	Code	Reason
//----------------------------------------------------------------------------------
//SIGILL	ILL_ILLOPC	illegal opcode
//ILL_ILLOPN	illegal operand
//ILL_ILLADR	illegal addressing mode
//ILL_ILLTRP	illegal trap
//ILL_PRVOPC	privileged opcode
//ILL_PRVREG	privileged register
//ILL_COPROC	coprocessor error
//ILL_BADSTK	internal stack error
//SIGFPE	FPE_INTDIV	integer divide by zero
//FPE_INTOVF	integer overflow
//FPE_FLTDIV	floating point divide by zero
//FPE_FLTOVF	floating point overflow
//FPE_FLTUND	floating point underflow
//FPE_FLTRES	floating point inexact result
//FPE_FLTINV	invalid floating point operation
//FPE_FLTSUB	subscript out of range
//SIGSEGV	SEGV_MAPERR	address not mapped to object
//SEGV_ACCERR	invalid permissions for mapped object
//SIGBUS	BUS_ADRALN	invalid address alignment
//BUS_ADRERR	non-existent physical address
//BUS_OBJERR	object specific hardware error
//SIGTRAP	TRAP_BRKPT	process breakpoint
//TRAP_TRACE	process trace trap
//SIGCHLD	CLD_EXITED	child has exited
//CLD_KILLED	child has terminated abnormally and did not create a core file
//CLD_DUMPED	child has terminated abnormally and created a core file
//CLD_TRAPPED	traced child has trapped
//CLD_STOPPED	child has stopped
//CLD_CONTINUED	stopped child has continued
//SIGPOLL	POLL_IN	data input available
//POLL_OUT	output buffers available
//POLL_MSG	input message available
//POLL_ERR	I/O error
//POLL_PRI	high priority input available
//POLL_HUP	device disconnected
//SI_USER	signal sent by kill()
//SI_QUEUE	signal sent by the sigqueue()
//SI_TIMER	signal generated by expiration of a timer set by timer_settime()
//SI_ASYNCIO	signal generated by completion of an asynchronous I/O request
//SI_MESGQ	signal generated by arrival of a message on an empty message queue
//==================================================================================


#define ILL_ILLOPN	// illegal operand
#define ILL_ILLADR	// illegal addressing mode
#define ILL_ILLTRP	// illegal trap
#define ILL_PRVOPC	// privileged opcode
#define ILL_PRVREG	// privileged register
#define ILL_COPROC	// coprocessor error
#define ILL_BADSTK	// internal stack error
#define SIGFPE	    // integer divide by zero
#define FPE_INTDIV	// integer divide by zero
#define FPE_INTOVF	// integer overflow
#define FPE_FLTDIV	// floating point divide by zero
#define FPE_FLTOVF	// floating point overflow
#define FPE_FLTUND	// floating point underflow
#define FPE_FLTRES	// floating point inexact result
#define FPE_FLTINV	// invalid floating point operation
#define FPE_FLTSUB	// subscript out of range
#define	SEGV_MAPERR	// address not mapped to object
#define SIGSEGV		// address not mapped to object
#define SEGV_ACCERR	// invalid permissions for mapped object
#define SIGBUS	    // invalid address alignment
#define	BUS_ADRALN	// invalid address alignment
#define BUS_ADRERR	// non-existent physical address
#define BUS_OBJERR	// object specific hardware error
#define SIGTRAP	    // process breakpoint
#define	TRAP_BRKPT	// process breakpoint
#define TRAP_TRACE	// process trace trap
#define SIGCHLD	    // child has exited
#define	CLD_EXITED	// child has exited
#define CLD_KILLED	// child has terminated abnormally and did not create a core file
#define CLD_DUMPED	// child has terminated abnormally and created a core file
#define CLD_TRAPPED	// traced child has trapped
#define CLD_STOPPED	// child has stopped
#define CLD_CONTINUED	// stopped child has continued
#define SIGPOLL	    // data input available
#define	POLL_IN	    // data input available
#define POLL_OUT	// output buffers available
#define POLL_MSG	// input message available
#define POLL_ERR	// I/O error
#define POLL_PRI	// high priority input available
#define POLL_HUP	// device disconnected
#define SI_USER	    // signal sent by kill()
#define SI_QUEUE	// signal sent by the sigqueue()
#define SI_TIMER	// signal generated by expiration of a timer set by timer_settime()
#define SI_ASYNCIO	// signal generated by completion of an asynchronous I/O request
#define SI_MESGQ	// signal generated by arrival of a message on an empty message queue

// Implementations may support additional si_code values not included in this list, may generate values included in this list under circumstances other than those described in this list, and may contain extensions or limitations that prevent some values from being generated. Implementations will not generate a different value from the ones described in this list for circumstances described in this list.
// In addition, the following signal-specific information will be available:

//==================================================================================
//Signal	Member	Value
//----------------------------------------------------------------------------------
//SIGILL
//SIGFPE	void * si_addr	address of faulting instruction
//SIGSEGV
//SIGBUS	void * si_addr	address of faulting memory reference
//SIGCHLD	pid_t si_pid
//int si_status
//uid_t si_uid	child process ID
//exit value or signal
//real user ID of the process that sent the signal
//SIGPOLL	long si_band	band event for POLL_IN, POLL_OUT or POLL_MSG
//==================================================================================




void   (*bsd_signal(int, void(*)(int)))(int);
int    kill(pid_t, int);
int    killpg(pid_t, int);
int    pthread_kill(pthread_t, int);
int    pthread_sigmask(int, const sigset_t *, sigset_t *);
int    raise(int);
int    sigaction(int, const struct sigaction *, struct sigaction *);
int    sigaddset(sigset_t *, int);
int    sigaltstack(const stack_t *, stack_t *);
int    sigdelset(sigset_t *, int);
int    sigemptyset(sigset_t *);
int    sigfillset(sigset_t *);
int    sighold(int);
int    sigignore(int);
int    siginterrupt(int, int);
int    sigismember(const sigset_t *, int);
void   (*signal(int, void(*)(int)))(int);
int    sigpause(int);
int    sigpending(sigset_t *);
int    sigprocmask(int, const sigset_t *, sigset_t *);
int    sigqueue(pid_t, int, const union sigval);
int    sigrelse(int);
void   (*sigset(int, void(*)(int)))(int);
int    sigstack(struct sigstack *ss, struct sigstack *oss);
int    sigsuspend(const sigset_t *);
int    sigtimedwait(const sigset_t *, siginfo_t *, const struct timespec *);
int    sigwait(const sigset_t *set, int *sig);
int    sigwaitinfo(const sigset_t *, siginfo_t *);



#endif // !_SIGNAL_H_




/*

// 高精度时钟
struct timespec ts;
ts.tv_sec = 1;// 秒
ts.tv_nsec = 500000000;// 纳秒 10^-9
nanosleep(&ts, NULL);




void signal_handler_fun(int signum)
{
printf("-- %d\n", signum);
}

int main(int argc, char *argv[])
{
// signal(SIGINT, SIG_IGN);// 忽略Ctrl+C信号
// signal(SIGINT, SIG_DFL);// 恢复对Ctrl+C信号的默认处理
// signal(SIGINT, signal_handler_fun);// 自定义Ctrl+C信号处理
signal(SIGQUIT, signal_handler_fun);// 自定义Ctrl+C信号处理

while (1);

return 0;
}


SIGINT: Ctrl+C
SIGKILL:不可被屏蔽
SIGSTOP:不可被屏蔽

Signal	Description
SIGABRT	由调用abort函数产生，进程非正常退出
SIGALRM	用alarm函数设置的timer超时或setitimer函数设置的interval timer超时
SIGBUS	某种特定的硬件异常，通常由内存访问引起
SIGCANCEL	由Solaris Thread Library内部使用，通常不会使用
SIGCHLD	进程Terminate或Stop的时候，SIGCHLD会发送给它的父进程。缺省情况下该Signal会被忽略
SIGCONT	当被stop的进程恢复运行的时候，自动发送
SIGEMT	和实现相关的硬件异常
SIGFPE	数学相关的异常，如被0除，浮点溢出，等等
SIGFREEZE	Solaris专用，Hiberate或者Suspended时候发送
SIGHUP	发送给具有Terminal的Controlling Process，当terminal 被disconnect时候发送
SIGILL	非法指令异常
SIGINFO	BSD signal。由Status Key产生，通常是CTRL+T。发送给所有Foreground Group的进程
SIGINT	由Interrupt Key产生，通常是CTRL+C或者DELETE。发送给所有ForeGround Group的进程
SIGIO	异步IO事件
SIGIOT	实现相关的硬件异常，一般对应SIGABRT
SIGKILL	无法处理和忽略。中止某个进程
SIGLWP	由Solaris Thread Libray内部使用
SIGPIPE	在reader中止之后写Pipe的时候发送
SIGPOLL	当某个事件发送给Pollable Device的时候发送
SIGPROF	Setitimer指定的Profiling Interval Timer所产生
SIGPWR	和系统相关。和UPS相关。
SIGQUIT	输入Quit Key的时候（CTRL+\）发送给所有Foreground Group的进程
SIGSEGV	非法内存访问
SIGSTKFLT	Linux专用，数学协处理器的栈异常
SIGSTOP	中止进程。无法处理和忽略。
SIGSYS	非法系统调用
SIGTERM	请求中止进程，kill命令缺省发送
SIGTHAW	Solaris专用，从Suspend恢复时候发送
SIGTRAP	实现相关的硬件异常。一般是调试异常
SIGTSTP	Suspend Key，一般是Ctrl+Z。发送给所有Foreground Group的进程
SIGTTIN	当Background Group的进程尝试读取Terminal的时候发送
SIGTTOU	当Background Group的进程尝试写Terminal的时候发送
SIGURG	当out-of-band data接收的时候可能发送
SIGUSR1	用户自定义signal 1
SIGUSR2	用户自定义signal 2
SIGVTALRM	setitimer函数设置的Virtual Interval Timer超时的时候
SIGWAITING	Solaris Thread Library内部实现专用
SIGWINCH	当Terminal的窗口大小改变的时候，发送给Foreground Group的所有进程
SIGXCPU	当CPU时间限制超时的时候
SIGXFSZ	进程超过文件大小限制
SIGXRES	Solaris专用，进程超过资源限制的时候发


*/













