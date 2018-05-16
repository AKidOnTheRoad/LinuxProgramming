#include <stdio.h>
#include <signal.h>
#include <errno.h>

typedef void (*sighandler_t)(int);

void sigHandler(int sig)
{
	if (sig == SIGINT)
	{
		printf("signal !!!\n");
		return ;
	}

	printf("sigquit!!!\n");
	return;

}

int main(int argc, const char *argv[])
{
	int j;

	if (signal(SIGINT, &sigHandler) == SIG_ERR)
		perror("signal");

	if (signal(SIGQUIT, &sigHandler) == SIG_ERR)
		perror("signal");

	for (j=0; ; j++)
	{
		printf("j:%d\n",j);
		sleep(3);
	}

	return 0;
}
