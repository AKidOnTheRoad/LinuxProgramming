#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

typedef void (*sighandler_t)(int);

static sigjmp_buf env;
static  int flag = 0;
void sigHandler(int sig)
{
	int j = 0;
	for(j = 0; j < 1000000000; j++)
		;
	printf("flag:%d\n",flag++);
	//	printf("flag:%d\n",flag);
	//printf("%s\n",strsignal(sig));
	//	siglongjmp(env,1);
	//	_exit(1);
	return ;
}


int main(int argc, const char *argv[])
{
	int j;
	struct sigaction sigact;

	sigact.sa_handler = sigHandler;
	//sigaddset(&(sigact.sa_mask), SIGINT|SIGQUIT);
	sigemptyset(&(sigact.sa_mask));
	sigact.sa_flags = 0;
	sigact.sa_restorer = NULL;
	
	//printf("%d\n",SA_NODEFER);

	//sigaction(SIGABRT, &sigact, NULL);
	
	sigaction(SIGINT, &sigact, NULL);
	sigaction(SIGQUIT, &sigact, NULL);


	//	sigsetjmp(env,1);

	for(;;)
		pause();
	return 0;
}
