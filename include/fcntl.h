
#ifndef _FCNTL_H_
#define _FCNTL_H_


 
#define F_DUPFD
// Duplicate file descriptor.
#define F_GETFD
// Get file descriptor flags.
#define F_SETFD
// Set file descriptor flags.
#define F_GETFL
// Get file status flags and file access modes.
#define F_SETFL
// Set file status flags.
#define F_GETLK
// Get record locking information.
#define F_SETLK
// Set record locking information.
#define F_SETLKW
// Set record locking information; wait if blocked.
// File descriptor flags used for fcntl():

#define FD_CLOEXEC
// Close the file descriptor upon execution of an exec family function.
// Values for l_type used for record locking with fcntl() (the following values are unique):

#define F_RDLCK
// Shared or read lock.
#define F_UNLCK
// Unlock.
#define F_WRLCK
// Exclusive or write lock.
// The values used for l_whence, SEEK_SET, SEEK_CUR and SEEK_END are defined as described in <unistd.h>.

// The following four sets of values for oflag used by open() are bitwise distinct:

#define O_CREAT
// Create file if it does not exist.
#define O_EXCL
// Exclusive use flag.
#define O_NOCTTY
// Do not assign controlling terminal.
#define O_TRUNC
// Truncate flag.
// File status flags used for open() and fcntl():

#define O_APPEND
// Set append mode.
#define O_DSYNC
// Write according to synchronised I/O data integrity completion.
#define O_NONBLOCK
// Non-blocking mode.
#define O_RSYNC
// Synchronised read I/O operations.
#define O_SYNC
// Write according to synchronised I/O file integrity completion.
// Mask for use with file access modes:

#define O_ACCMODE
// Mask for file access modes.
// File access modes used for open() and fcntl():

#define O_RDONLY
// Open for reading only.
#define O_RDWR
// Open for reading and writing.
#define O_WRONLY
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


















