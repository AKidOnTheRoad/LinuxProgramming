#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>


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
	pid_t pid;
	pid = fork();
	struct rusage usage;
	if (pid < 0) {
		printf("pid error!!!\n");
		return -1;
	} else if (pid == 0)
	{
		int a[100];
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		printf("I am a child process.\n");
		sleep(2);
		exit(0);
	} else {
		printf("I am a parent process.\n");
		getrusage(RUSAGE_CHILDREN, &usage);
		printf("111 user cpu time:%ld\n", usage.ru_isrss);
		wait(NULL);
		getrusage(RUSAGE_CHILDREN, &usage);
		printf("222 user cpu time:%ld\n", usage.ru_isrss);
	}

	return 0;
}
