
#ifndef _FCNTL_H_
#define _FCNTL_H_


 
#define F_DUPFD 0
// Duplicate file descriptor.
#define F_GETFD 0
// Get file descriptor flags.
#define F_SETFD 0
// Set file descriptor flags.
#define F_GETFL 0
// Get file status flags and file access modes.
#define F_SETFL 0
// Set file status flags.
#define F_GETLK 0
// Get record locking information.
#define F_SETLK 0
// Set record locking information.
#define F_SETLKW 0
// Set record locking information; wait if blocked.
// File descriptor flags used for fcntl():

#define FD_CLOEXEC 0
// Close the file descriptor upon execution of an exec family function.
// Values for l_type used for record locking with fcntl() (the following values are unique):

#define F_RDLCK 0
// Shared or read lock.
#define F_UNLCK 0
// Unlock.
#define F_WRLCK 0
// Exclusive or write lock.
// The values used for l_whence, SEEK_SET, SEEK_CUR and SEEK_END are defined as described in <unistd.h>.

// The following four sets of values for oflag used by open() are bitwise distinct:

#define O_CREAT 0
// Create file if it does not exist.
#define O_EXCL 0
// Exclusive use flag.
#define O_NOCTTY 0
// Do not assign controlling terminal.
#define O_TRUNC 0
// Truncate flag.
// File status flags used for open() and fcntl():

#define O_APPEND 0
// Set append mode.
#define O_DSYNC 0
// Write according to synchronised I/O data integrity completion.
#define O_NONBLOCK 0
// Non-blocking mode.
#define O_RSYNC 0
// Synchronised read I/O operations.
#define O_SYNC 0
// Write according to synchronised I/O file integrity completion.
// Mask for use with file access modes:

#define O_ACCMODE 0
// Mask for file access modes.
// File access modes used for open() and fcntl():

#define O_RDONLY 0
// Open for reading only.
#define O_RDWR 0
// Open for reading and writing.
#define O_WRONLY 0
// Open for writing only.
// The symbolic names for file modes for use as values of mode_t are defined as described in <sys/stat.h>.

// The structure flock describes a file lock. It includes the following members:


typedef short l_type;   // type of lock; F_RDLCK, F_WRLCK, F_UNLCK
typedef short l_whence; // flag for starting offset
typedef off_t l_start;  // relative offset in bytes
typedef off_t l_len;    // size; if 0 then until EOF
typedef pid_t l_pid;    // process ID of the process holding the lock; returned with F_GETLK

// The off_t and pid_t types are defined as described in <sys/types.h>.

// The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


int  creat(const char *, mode_t);
int  fcntl(int, int, ...);
int  open(const char *, int, ...);



















#endif // !_FCNTL_H_


















