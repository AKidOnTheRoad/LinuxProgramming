/***************************************************************************
  > File name:      test_main.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2017-12-07 19:16:22 weeks:49
***************************************************************************/

#include "test_main.h"

sem_t mysemid1, mysemid2;
int MyCount = 0;

void * threadfun1(void * arg)
{
	sem_wait(&mysemid1);
//	printf("count1:%d\n",(*((int*)arg)));
	sem_post(&mysemid2);

	return (void *)0;
}

void * threadfun2(void * arg)
{
	sem_wait(&mysemid2);
//	(*((int * )arg))++;
//	printf("count2:%d\n",*((int*)arg));
	sem_post(&mysemid1);

	return (void *)0;
}

void * increase_num(void * arg)
{
	int i;
	for (i = 0; i < 100; i++)
		MyCount++;
	return (void*)0;
}

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
int main(int argc, const char *argv[])
{
	pthread_t mythread1, mythread2;
	int count = 2;

	sem_init(&mysemid1,1,0);
	sem_init(&mysemid2,1,1);

//	if(THREAD_SUCCESS !=  pthread_create(&mythread1,NULL,&threadfun1,NULL))
//	{
//		printf("pthread_create error !!\n");
//		return -1;
//	}
//
//	if(THREAD_SUCCESS != pthread_create(&mythread2,NULL,&threadfun2,NULL))
//	{
//		printf("pthread_create error!!!\n");
//		return -2;
//	}

	if(THREAD_SUCCESS !=  pthread_create(&mythread1,NULL,&increase_num,NULL))
	{
		printf("pthread_create error !!\n");
		return -1;
	}

	if(THREAD_SUCCESS != pthread_create(&mythread2,NULL,&increase_num,NULL))
	{
		printf("pthread_create error!!!\n");
		return -2;
	}


	pthread_join(mythread1,NULL);
	pthread_join(mythread2,NULL);


	printf("Mycount:%d\n",MyCount);

	sem_destroy(&mysemid2);
	sem_destroy(&mysemid1);

//	pthread_cancel(mythread1);
//	pthread_cancel(mythread2);
	
#ifdef DEBUG
	printf("123456!!!\n");
#endif
	return 0;
}
