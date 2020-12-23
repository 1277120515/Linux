#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H	1
#include <sys/types.h>

typedef int sem_t;
// used in performing semaphore operations. 
// The semaphore may be implemented using a file descriptor, 
// in which case applications are able to open up at least a total of OPEN_MAX files and semaphores


// 初始化由 sem 指向的信号对象，并给它一个初始的整数值 value。
// pshared 控制信号量的类型，值为 0 代表该信号量用于多线程间的同步,值如果大于 0 表示可以共享，用于多个相关进程间的同步
int sem_init(sem_t *sem, int pshared, unsigned int value);

// 若sem value > 0，则该信号量值减去 1 并立即返回。
// 若sem value = 0，则阻塞直到 sem value > 0，此时立即减去 1，然后返回。
int sem_wait(sem_t * sem);

// 非阻塞的函数，它会尝试获取获取 sem value 值，
// 如果 sem value = 0，不是阻塞住，而是直接返回一个错误 EAGAIN。
int sem_trywait(sem_t * sem);

// 用于对用完的信号量的清理。
int sem_destroy(sem_t * sem);

// 把指定的信号量 sem 的值加 1，唤醒正在等待该信号量的任意线程。
int sem_post(sem_t * sem);


int    sem_close(sem_t *);
int    sem_getvalue(sem_t *, int *);
sem_t *sem_open(const char *, int, ...);
int sem_unlink(const char *);

#endif	 
