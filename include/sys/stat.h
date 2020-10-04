#ifndef _STAT_H_
#define _STAT_H_
#include <sys/types.h>


// The structure stat contains at least the following members:

struct stat
{
    dev_t     st_dev;//      ID of device containing file
    ino_t     st_ino;//     file serial number
    mode_t    st_mode;//    mode of file (see below)
    nlink_t   st_nlink;//   number of links to the file
    uid_t     st_uid;//    user ID of file
    gid_t     st_gid;//     group ID of file
    dev_t     st_rdev;//    device ID (if file is character or block special)
    off_t     st_size;//    file size in bytes (if file is a regular file)
    time_t    st_atime;//   time of last access
    time_t    st_mtime;//   time of last data modification
    time_t    st_ctime;//   time of last status change
    blksize_t st_blksize;// a filesystem-specific preferred I/O block size for this object.  
                         // In some filesystem types, this may vary from file to file
    blkcnt_t  st_blocks;//  number of blocks allocated for this object
};

// The following symbolic names for the values of st_mode are also defined:

// File type:

#define S_IFMT
// type of file
#define S_IFBLK
// block special
#define S_IFCHR
// character special
#define S_IFIFO
// FIFO special
#define S_IFREG
// regular
#define S_IFDIR
// directory
#define S_IFLNK
// symbolic link
#define S_IFSOCK
// File mode bits:

#define S_IRWXU
// read, write, execute/search by owner
#define S_IRUSR
// read permission, owner
#define S_IWUSR
// write permission, owner
#define S_IXUSR
// execute/search permission, owner
#define S_IRWXG
// read, write, execute/search by group
#define S_IRGRP
// read permission, group
#define S_IWGRP
// write permission, group
#define S_IXGRP
// execute/search permission, group
#define S_IRWXO
// read, write, execute/search by others
#define S_IROTH
// read permission, others
#define S_IWOTH
// write permission, others
#define S_IXOTH
// execute/search permission, others
#define S_ISUID
// set-user-ID on execution
#define S_ISGID
// set-group-ID on execution
#define S_ISVTX
// on directories, restricted deletion flag
// The bits defined by S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH, S_ISUID, S_ISGID  and S_ISVTX are unique.

// S_IRWXU is the bitwise OR of S_IRUSR, S_IWUSR and S_IXUSR.

// S_IRWXG is the bitwise OR of S_IRGRP, S_IWGRP and S_IXGRP.

// S_IRWXO is the bitwise OR of S_IROTH, S_IWOTH and S_IXOTH.

// Implementations may OR other implementation-dependent bits into S_IRWXU, S_IRWXG and S_IRWXO, but they will not overlap any of the other bits defined in this document. The file permission bits are defined to be those corresponding to the bitwise inclusive OR of S_IRWXU, S_IRWXG and S_IRWXO.


#define S_ISBLK(m) 1
// Test for a block special file.
#define S_ISCHR(m) 1
// Test for a character special file.
#define S_ISDIR(m) 1
// Test for a directory.
#define S_ISFIFO(m) 1
// Test for a pipe or FIFO special file.
#define S_ISREG(m) 1
// Test for a regular file.
#define S_ISLNK(m) 1
// Test for a symbolic link.
#define S_ISSOCK(m) 1

// The implementation may implement message queues, semaphores, or shared memory objects as distinct file types. 
// The following macros test whether a file is of the specified type. 
// The value of the buf argument supplied to the macros is a pointer to a stat structure. 
// The macro evaluates to a non-zero value if the specified object is implemented as a distinct file type and the specified file type is contained in the stat structure referenced by buf. 
// Otherwise, the macro evaluates to zero.

#define S_TYPEISMQ(buf) 1
// Test for a message queue
#define S_TYPEISSEM(buf) 1
// Test for a semaphore
#define S_TYPEISSHM(buf) 1
// Test for a shared memory object


// The following are declared as functions and may also be defined as macros. 
// Function prototypes must be provided for use with an ISO C compiler.


int    chmod(const char *, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat *);
int    lstat(const char *, struct stat *);
int    mkdir(const char *, mode_t);
int    mkfifo(const char *, mode_t);
int    mknod(const char *, mode_t, dev_t);
int    stat(const char *, struct stat *);
mode_t umask(mode_t);


#endif // !_STAT_H_
