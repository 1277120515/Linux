
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
    void * addr,    // Ҫ���ļ�ӳ�䵽���ڴ��ַ��һ��Ӧ�ô���NULL����Linux�ں�ָ����
    size_t length,  // Ҫӳ����ļ����ݳ��ȡ�
    int prot,       // ӳ����ڴ�����Ĳ���Ȩ��, ����PROT_READ��PROT_WRITE��PROT_READ|PROT_WRITE
    int flags,      // ��־λ������������MAP_SHARED��MAP_PRIVATE��MAP_ANONYMOUS��
                        // MAP_SHARED:  �����������ڽ��̼�ͨ�ţ����û�������־�����Ľ��̼�ʹ�ܴ��ļ���Ҳ���������ݡ�
                        // MAP_PRIVATE : ֻ�н����Լ��õ��ڴ�����
                        // MAP_ANONYMOUS : ����ӳ����
    int fd,         // ��������ӳ�������ļ����������� shm_open�򿪻���open�򿪵��ļ���
    off_t offset    // ӳ���ļ���ƫ�ƣ�Ӧ�ð�4096�ֽڶ��롣
);                  // ����ֵ:�ɹ�����ӳ����ڴ��ַ�� ʧ�ܷ���NULL��
int    mprotect(void *, size_t, int);
int    msync(void *, size_t, int);
int    munlock(const void *, size_t);
int    munlockall(void);
int    munmap(void *, size_t);
int    shm_open(const char *, int, mode_t);
int    shm_unlink(const char *);



#endif



