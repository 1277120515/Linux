
#ifndef _UTIME_H_
#define _UTIME_H_




struct utimbuf
{
    time_t    actime;//    access time
    time_t    modtime;//  modification time
};

int utime(const char *, const struct utimbuf *);

/*

*/









#endif // !_UTIME_H_





















