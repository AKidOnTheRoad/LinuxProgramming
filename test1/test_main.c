/***************************************************************************
  > File name:      test_main.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2017-12-04 16:45:52 weeks:49
***************************************************************************/

#include "test_main.h"


sem_t mySemId1,mySemId2;
int gNum = 2;


int max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}


void * pthread_fun(void * arg)
{
	sem_wait(&mySemId1);
	gNum ++;
	printf(" pthread1 gNum:%d\n",gNum);
	//printf("123456!!!\n");
	//printf("char:%d\n",*((char*)arg));
//	int count = 0;
//	for (count = 0; count < 3; count++)
//		printf("this is a child process count:%d\n",count);

	sem_post(&mySemId2);

	return (void *)0;
}

void * pthread_fun2(void *arg)
{
//	sleep(1);
	sem_wait(&mySemId2);
//	printf("pthread_fun2 success!!!\n");
	gNum += 10;
	printf("pthread2 gNum:%d\n",gNum);
	sem_post(&mySemId1);

	return (void *)0;	
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
	tTmpStruct *   MyTemp;
//	tTmpStruct  DebugTmp;

	if((MyTemp = MYMALLOC(sizeof(tTmpStruct),tTmpStruct)) == NULL)
		printf("malloc error !!!\n");

	//printf("MyTemp:%p  MyTemp->OwnId:%p MyTemp->TmpValue:%p  MyTemp->StringValue:%p\n",MyTemp,MyTemp->OwnId,MyTemp->TmpValue,MyTemp->StringValue);
	
	//printf("MyTemp->TmpValue:%p \n",&(MyTemp->OwnId));

//	*(MyTemp->TmpValue) = 11;
	
//	printf("addr:%p \n",DebugTmp.TmpValue);
//	*(DebugTmp.TmpValue) = 111;

	MYFREE(MyTemp);

	pthread_t pthread_id1, pthread_id2;

	int ret  = 0;
	int count = 0;

	int m = 123;
	int (*fun) (int,int);
	int (*fun1)(int a,int b);

	fun = max;
	fun1 = max;
	printf("value:%d  value:%d\n",fun(1,12),(*fun1)(1,34));
	if ( sem_init(&mySemId1,1,1) != 0)
	{
		printf("sem_init　error!!!\n");
		return -1;
	}

	if (sem_init(&mySemId2,1,0) != 0)
	{
		printf("sem_init SemId2 error!!!\n");
		return -1;
	}


	ret = pthread_create(&pthread_id1,NULL,(void *)pthread_fun,&m);

	ret |= pthread_create(&pthread_id2,NULL,(void *)pthread_fun2,NULL);


	if (ret)
		printf("error!!!\n");

	for (count = 0; count < 3; count++)
		printf("this is a parent process !!!\n");

	printf("main process　gNum:%d\n",gNum);

	pthread_join(pthread_id1,NULL);
	pthread_join(pthread_id2,NULL);

	sem_destroy(&mySemId1);
	sem_destroy(&mySemId2);

	pthread_cancel(pthread_id1);
	pthread_cancel(pthread_id2);
	return 0;
}
