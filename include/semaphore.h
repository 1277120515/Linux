#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H	1
#include <sys/types.h>

typedef int sem_t;
// used in performing semaphore operations. 
// The semaphore may be implemented using a file descriptor, 
// in which case applications are able to open up at least a total of OPEN_MAX files and semaphores


// ��ʼ���� sem ָ����źŶ��󣬲�����һ����ʼ������ֵ value��
// pshared �����ź��������ͣ�ֵΪ 0 ������ź������ڶ��̼߳��ͬ��,ֵ������� 0 ��ʾ���Թ������ڶ����ؽ��̼��ͬ��
int sem_init(sem_t *sem, int pshared, unsigned int value);

// ��sem value > 0������ź���ֵ��ȥ 1 ���������ء�
// ��sem value = 0��������ֱ�� sem value > 0����ʱ������ȥ 1��Ȼ�󷵻ء�
int sem_wait(sem_t * sem);

// �������ĺ��������᳢�Ի�ȡ��ȡ sem value ֵ��
// ��� sem value = 0����������ס������ֱ�ӷ���һ������ EAGAIN��
int sem_trywait(sem_t * sem);

// ���ڶ�������ź���������
int sem_destroy(sem_t * sem);

// ��ָ�����ź��� sem ��ֵ�� 1���������ڵȴ����ź����������̡߳�
int sem_post(sem_t * sem);


int    sem_close(sem_t *);
int    sem_getvalue(sem_t *, int *);
sem_t *sem_open(const char *, int, ...);
int sem_unlink(const char *);

#endif	 
