#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>


void *threadFunc(void *arg)
{
	printf("%s\n",arg);
	printf("Thread id:%lu\n", (unsigned long)pthread_self());
	//printf("ID:%d\n", (int)gettid());
	return (void*)strlen(arg);
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
	void *res;
	int s = 0;
	pthread_create(&t1, NULL, threadFunc, "Hello My Hometown.");

	printf("Message from main().\n");
	pthread_join(t1, &res);

	printf("res:%d\n", (int)res);


	if (pthread_join(pthread_self(), NULL) != 0)
		printf("error!!!\n");
	return 0;
}
