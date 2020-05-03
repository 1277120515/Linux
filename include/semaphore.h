

#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H	1
#include <sys/types.h>

typedef int sem_t;
// used in performing semaphore operations. 
// The semaphore may be implemented using a file descriptor, 
// in which case applications are able to open up at least a total of OPEN_MAX files and semaphores

int    sem_close(sem_t *);
int    sem_destroy(sem_t *);
int    sem_getvalue(sem_t *, int *);
int    sem_init(sem_t *, int, unsigned int);
sem_t *sem_open(const char *, int, ...);
int    sem_post(sem_t *);
int    sem_trywait(sem_t *);
int    sem_unlink(const char *);
int    sem_wait(sem_t *);

#endif	 
