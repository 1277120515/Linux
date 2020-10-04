
#ifndef _MMAN_H_
#define _MMAN_H_

#include <sys/types.h>


// The following protection options are defined:
#define PROT_READ 0
// Page can be read.
#define PROT_WRITE 0
// Page can be written.
#define PROT_EXEC 0
// Page can be executed.
#define PROT_NONE 0
// Page can not be accessed.
// The following flag options are defined:

#define MAP_SHARED 0
// Share changes.
#define MAP_PRIVATE 0
// Changes are private.
#define MAP_FIXED 0
// Interpret addr exactly.
// The following flags are defined for msync():

#define MS_ASYNC 0
// Perform asynchronous writes.
#define MS_SYNC 0
// Perform synchronous writes.
#define MS_INVALIDATE 0
// Invalidate mappings.
// The following symbolic constants are defined for the mlockall() function:

#define MCL_CURRENT 0
// Lock currently mapped pages.
#define MCL_FUTURE 0
// Lock pages that become mapped.
// The symbolic constant MAP_FAILED is defined to indicate a failure from the mmap() function.

// The size_t and off_t types are defined as described in <sys/types.h>.
// The following are declared in <sys/mman.h> as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


int    mlock(const void *, size_t);
int    mlockall(int);
void  * mmap(
    void * addr,    // 要将文件映射到的内存地址，一般应该传递NULL来由Linux内核指定。
    size_t length,  // 要映射的文件数据长度。
    int prot,       // 映射的内存区域的操作权限, 包括PROT_READ、PROT_WRITE、PROT_READ|PROT_WRITE
    int flags,      // 标志位参数，包括：MAP_SHARED、MAP_PRIVATE与MAP_ANONYMOUS。
                        // MAP_SHARED:  建立共享，用于进程间通信，如果没有这个标志，则别的进程即使能打开文件，也看不到数据。
                        // MAP_PRIVATE : 只有进程自己用的内存区域
                        // MAP_ANONYMOUS : 匿名映射区
    int fd,         // 用来建立映射区的文件描述符，用 shm_open打开或者open打开的文件。
    off_t offset    // 映射文件的偏移，应该按4096字节对齐。
);                  // 返回值:成功返回映射的内存地址， 失败返回NULL。
int    mprotect(void *, size_t, int);
int    msync(void *, size_t, int);
int    munlock(const void *, size_t);
int    munlockall(void);
int    munmap(void *, size_t);
int    shm_open(const char *, int, mode_t);
int    shm_unlink(const char *);



#endif



