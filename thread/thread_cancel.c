#include <stdio.h>
#include <pthread.h>

void *threadFun(void * arg)
{
	int loop = 0;
	for (;;)
		printf("loop:%d\n",(++loop));

	return NULL;
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
	pthread_t t1;
	void * flag;
	pthread_create(&t1, NULL, threadFun, NULL);

	sleep(3);
	pthread_cancel(t1);

	pthread_join(t1,&flag);

	if (flag == PTHREAD_CANCELED)
		printf("Thread was canceled.\n");
	else
		printf("Thread was not canceled.\n");

	return 0;
}
