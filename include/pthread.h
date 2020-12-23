
// httpspubs.opengroup.orgonlinepubs007908799xnsinet_addr.html
#ifndef _PTHREAD_H
#define _PTHREAD_H	1



#define PTHREAD_CANCEL_ASYNCHRONOUS     (void *)NULL
#define PTHREAD_CANCEL_ENABLE           (void *)NULL
#define PTHREAD_CANCEL_DEFERRED         (void *)NULL
#define PTHREAD_CANCEL_DISABLE          (void *)NULL
#define PTHREAD_CANCELED                (void *)NULL
#define PTHREAD_COND_INITIALIZER        (void *)NULL
#define PTHREAD_CREATE_DETACHED         (void *)NULL
#define PTHREAD_CREATE_JOINABLE         (void *)NULL
#define PTHREAD_EXPLICIT_SCHED          (void *)NULL
#define PTHREAD_INHERIT_SCHED           (void *)NULL
#define PTHREAD_MUTEX_DEFAULT           (void *)NULL
#define PTHREAD_MUTEX_ERRORCHECK        (void *)NULL
#define PTHREAD_MUTEX_NORMAL            (void *)NULL
#define PTHREAD_MUTEX_INITIALIZER       (void *)NULL
#define PTHREAD_MUTEX_RECURSIVE         (void *)NULL
#define PTHREAD_ONCE_INIT               (void *)NULL
#define PTHREAD_PRIO_INHERIT            (void *)NULL
#define PTHREAD_PRIO_NONE               (void *)NULL
#define PTHREAD_PRIO_PROTECT            (void *)NULL
#define PTHREAD_PROCESS_SHARED          (void *)NULL
#define PTHREAD_PROCESS_PRIVATE         (void *)NULL
#define PTHREAD_RWLOCK_INITIALIZER      (void *)NULL
#define PTHREAD_SCOPE_PROCESS           (void *)NULL
#define PTHREAD_SCOPE_SYSTEM            (void *)NULL








typedef struct _pthread_cond_t { int t; }   pthread_cond_t;
typedef unsigned long int           pthread_t;
typedef struct _pthread_attr_t { int t; }   pthread_attr_t;
typedef struct _pthread_mutex_t { int t; }   pthread_mutex_t;
typedef struct _pthread_mutexattr_t { int t; }   pthread_mutexattr_t;
typedef struct _pthread_mutexattr_t { int t; } pthread_condattr_t;
typedef struct _pthread_rwlock_t { int t; } pthread_rwlock_t;
typedef struct _pthread_key_t { int t; } pthread_key_t;
typedef struct _pthread_once_t { int t; } pthread_once_t;
typedef struct _pthread_rwlockattr_t { int t; } pthread_rwlockattr_t;






int   pthread_attr_destroy(pthread_attr_t *);
int   pthread_attr_getdetachstate(const pthread_attr_t *, int *);
int   pthread_attr_getguardsize(const pthread_attr_t *, size_t *);
int   pthread_attr_getinheritsched(const pthread_attr_t *, int *);
int   pthread_attr_getschedparam(const pthread_attr_t *, struct sched_param *);
int   pthread_attr_getschedpolicy(const pthread_attr_t *, int *);
int   pthread_attr_getscope(const pthread_attr_t *, int *);
int   pthread_attr_getstackaddr(const pthread_attr_t *, void **);
int   pthread_attr_getstacksize(const pthread_attr_t *, size_t *);
int   pthread_attr_init(pthread_attr_t *);
int   pthread_attr_setdetachstate(pthread_attr_t *, int);
int   pthread_attr_setguardsize(pthread_attr_t *, size_t);
int   pthread_attr_setinheritsched(pthread_attr_t *, int);
int   pthread_attr_setschedparam(pthread_attr_t *, const struct sched_param *);
int   pthread_attr_setschedpolicy(pthread_attr_t *, int);
int   pthread_attr_setscope(pthread_attr_t *, int);
int   pthread_attr_setstackaddr(pthread_attr_t *, void *);
int   pthread_attr_setstacksize(pthread_attr_t *, size_t);
int   pthread_cancel(pthread_t);
void  pthread_cleanup_push(void* , void *);
void  pthread_cleanup_pop(int);
int   pthread_cond_broadcast(pthread_cond_t *);
int   pthread_cond_destroy(pthread_cond_t *);
int   pthread_cond_init(pthread_cond_t *, const pthread_condattr_t *);
int   pthread_cond_signal(pthread_cond_t *);
int   pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, const struct timespec *);
int   pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
int   pthread_condattr_destroy(pthread_condattr_t *);
int   pthread_condattr_getpshared(const pthread_condattr_t *, int *);
int   pthread_condattr_init(pthread_condattr_t *);
int   pthread_condattr_setpshared(pthread_condattr_t *, int);
int   pthread_create(pthread_t *, const pthread_attr_t *,
    void *(*)(void *), void *);
int   pthread_detach(pthread_t);
int   pthread_equal(pthread_t, pthread_t);
void  pthread_exit(void *);
int   pthread_getconcurrency(void);
int   pthread_getschedparam(pthread_t, int *, struct sched_param *);
void *pthread_getspecific(pthread_key_t);
int   pthread_join(pthread_t, void **);
int   pthread_key_create(pthread_key_t *, void(*)(void *));
int   pthread_key_delete(pthread_key_t);
int   pthread_mutex_destroy(pthread_mutex_t *);
int   pthread_mutex_getprioceiling(const pthread_mutex_t *, int *);
int   pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
int   pthread_mutex_lock(pthread_mutex_t *);
int   pthread_mutex_setprioceiling(pthread_mutex_t *, int, int *);
int   pthread_mutex_trylock(pthread_mutex_t *);
int   pthread_mutex_unlock(pthread_mutex_t *);
int   pthread_mutexattr_destroy(pthread_mutexattr_t *);
int   pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_getprotocol(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_getpshared(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_gettype(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_init(pthread_mutexattr_t *);
int   pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int);
int   pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);
int   pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
int   pthread_mutexattr_settype(pthread_mutexattr_t *, int);
int   pthread_once(pthread_once_t *, void(*)(void));
int   pthread_rwlock_destroy(pthread_rwlock_t *);
int   pthread_rwlock_init(pthread_rwlock_t *, const pthread_rwlockattr_t *);
int   pthread_rwlock_rdlock(pthread_rwlock_t *);
int   pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int   pthread_rwlock_trywrlock(pthread_rwlock_t *);
int   pthread_rwlock_unlock(pthread_rwlock_t *);
int   pthread_rwlock_wrlock(pthread_rwlock_t *);
int   pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
int   pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *,
    int *);
int   pthread_rwlockattr_init(pthread_rwlockattr_t *);
int   pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);
pthread_t pthread_self(void);
int   pthread_setcancelstate(int, int *);
int   pthread_setcanceltype(int, int *);
int   pthread_setconcurrency(int);
int   pthread_setschedparam(pthread_t, int, const struct sched_param *);
int   pthread_setspecific(pthread_key_t, const void *);
void  pthread_testcancel(void);

#endif	

/***************************************************************************

#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <pthread.h>
//
//int gNum = 0;
//pthread_mutex_t gMutex;
//pthread_cond_t gCond;
//
//void * threadFun(void * args)
//{
//    while (1)
//    {
//        pthread_mutex_lock(&gMutex);
//        while (gNum <= 0)
//        {
//            pthread_cond_wait(&gCond, &gMutex);
//            printf("%lu\n", pthread_self());
//        }
//        printf("%s N = %d\n", (char *)args, gNum);
//        gNum--;
//        pthread_mutex_unlock(&gMutex);
//    }
//}
//
//int main()
//{
//    pthread_t pid1, pid2, pid3;
//
//    pthread_mutex_init(&gMutex, NULL);
//    pthread_cond_init(&gCond, NULL);
//
//    pthread_create(&pid1, NULL, threadFun, (void *)"Thread 1");
//    pthread_create(&pid2, NULL, threadFun, (void *)"Thread 2");
//
//    while (1)
//    {
//        pthread_mutex_lock(&gMutex);
//        gNum += 1;
//        pthread_cond_broadcast(&gCond); // 唤醒全部线程，但只有一个线程能够拿到锁；当拿到锁的线程unlock释放锁后，被唤醒的其他线程获取锁，开始执行while
//        // pthread_cond_signal(&gCond); // 唤醒一个线程，这个线程拿到锁，继续执行，其余未被唤醒的线程，仍然sleep
//
//        pthread_mutex_unlock(&gMutex);
//
//        sleep(1);
//    }
//
//    pthread_join(pid1, NULL);
//    pthread_join(pid2, NULL);
//
//    pthread_mutex_destroy(&gMutex);
//    pthread_cond_destroy(&gCond);
//}
***************************************************************************/