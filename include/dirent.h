#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <sys/types.h>
#define NAME_MAX 100

struct __dirstream
{
    void *__fd; /* `struct hurd_fd' pointer for descriptor.   */
    char *__data; /* Directory block.   */
    int __entry_data; /* Entry number `__data' corresponds to.   */
    char *__ptr; /* Current pointer into the block.   */
    int __entry_ptr; /* Entry number `__ptr' corresponds to.   */
    size_t __allocation; /* Space allocated for the block.   */
    size_t __size; /* Total valid data in the block.   */
};

typedef struct __dirstream DIR;

struct dirent
{
    long d_ino;                 // inode number �����ڵ�� 
    off_t d_off;                // offset to this dirent ��Ŀ¼�ļ��е�ƫ�� 
    unsigned short d_reclen;    // length of this d_name �ļ����� 
    unsigned char d_type;       // the type of d_name �ļ����� 
    char d_name[NAME_MAX + 1];  // file name (null-terminated) �ļ������255�ַ� 
};

int            closedir(DIR *);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *, struct dirent *, struct dirent **);
void           rewinddir(DIR *);
void           seekdir(DIR *, long int);
long int       telldir(DIR *);









#endif // !_DIRENT_H_
