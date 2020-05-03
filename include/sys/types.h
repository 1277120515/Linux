#ifndef _TYPES_H_
#define _TYPES_H_



typedef int blkcnt_t;
// Used for file block counts
typedef int blksize_t;
// Used for block sizes
typedef clock_t;
// Used for system times in clock ticks or CLOCKS_PER_SEC (see <time.h>).
typedef clockid_t;
// Used for clock ID type in the clock and timer functions.
typedef dev_t;
// Used for device IDs.
typedef unsigned int fsblkcnt_t;
// Used for file system block counts
typedef unsigned int fsfilcnt_t;
// Used for file system file counts
typedef gid_t;
// Used for group IDs.
typedef id_t;
// Used as a general identifier; can be used to contain at least a pid_t, uid_t or a gid_t.
typedef unsigned int ino_t;
// Used for file serial numbers.
typedef key_t;
// Used for interprocess communication.
typedef mode_t;
// Used for some file attributes.
typedef nlink_t;
// Used for link counts.
typedef int off_t;
// Used for file sizes.
typedef int pid_t;
// Used for process IDs and process group IDs.
typedef pthread_attr_t;
// Used to identify a thread attribute object.
typedef pthread_cond_t;
// Used for condition variables.
typedef pthread_condattr_t;
// Used to identify a condition attribute object.
typedef pthread_key_t;
// Used for thread-specific data keys.
typedef pthread_mutex_t;
// Used for mutexes.
typedef pthread_mutexattr_t;
// Used to identify a mutex attribute object.
typedef pthread_once_t;
// Used for dynamic package initialisation.
typedef pthread_rwlock_t;
// Used for read-write locks.
typedef pthread_rwlockattr_t;
// Used for read-write lock attributes.
typedef pthread_t;
// Used to identify a thread.
typedef unsigned int size_t;
// Used for sizes of objects.
typedef int ssize_t;//  [-1, SSIZE_MAX]
// Used for a count of bytes or an error indication.
typedef suseconds_t;// [-1, 1,000,000].
// Used for time in microseconds
typedef time_t;
// Used for time in seconds.
typedef timer_t;
// Used for timer ID returned by timer_create().
typedef uid_t;
// Used for user IDs.
typedef useconds_t;// [0, 1,000,000]
// Used for time in microseconds.

// All of the types are defined as arithmetic types of an appropriate length, with the following exceptions: 
// key_t, pthread_attr_t, pthread_cond_t, pthread_condattr_t, pthread_key_t, pthread_mutex_t, pthread_mutexattr_t, pthread_once_t, pthread_rwlock_t and pthread_rwlockattr_t.
// blkcnt_t and off_t are  extended signed integral types,
// fsblkcnt_t, fsfilcnt_t and ino_t are defined as  extended unsigned integral types,
// size_t is an unsigned integral type
// blksize_t, pid_t and ssize_t are signed integral types.
// The type ssize_t is capable of storing values at least in the range [-1, SSIZE_MAX].
// The type useconds_t is an unsigned integral type capable of storing values at least in the range [0, 1,000,000].
// The type suseconds_t is a signed integral type capable of storing values at least in the range [-1, 1,000,000].



#endif // !_TYPES_H_


















