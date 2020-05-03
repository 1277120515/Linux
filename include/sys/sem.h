
#ifndef _SEM_H_
#define _SEM_H_
#include <sys/ipc.h>

// The <sys/sem.h> header defines the following constants and structures.
// Semaphore operation flags:

#define  SEM_UNDO
// Set up adjust on exit entry.


// Command definitions for the function semctl():

#define GETNCNT
// Get semncnt.
#define GETPID
// Get sempid.
#define GETVAL
// Get semval.
#define GETALL
// Get all cases of semval.
#define GETZCNT
// Get semzcnt.
#define SETVAL
// Set semval.
#define SETALL
// Set all cases of semval.



struct semid_ds
{
    struct ipc_perm    sem_perm; // operation permission structure
    unsigned short int sem_nsems; //  number of semaphores in set
    time_t             sem_otime; // last semop^) time
    time_t             sem_ctime; //  last time changed by semctl()
};
// The pid_t, time_t, key_t and size_t types are defined as described in <sys/types.h>.

// A semaphore is represented by an anonymous structure containing the following members:

struct semaphore
{
    unsigned short int semval; //    semaphore value
    pid_t              sempid; //    process ID of last operation
    unsigned short int semncnt; //   number of processes waiting for semval to become greater than current value
    unsigned short int semzcnt; //   number of processes waiting for semval to become 0
};
// The structure sembuf contains the following members:

struct sembuf
{
    unsigned short int sem_num; //   semaphore number
    short int          sem_op; //    semaphore operation
    short int          sem_flg; //   operation flags
};
// The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


int   semctl(int, int, int, ...);
int   semget(key_t, int, int);
int   semop(int, struct sembuf *, size_t);


#endif // !_SEM_H_


















