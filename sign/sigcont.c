#include <stdio.h>
#include <signal.h>
#include <string.h>

void myhandler(int sig)
{
	printf("%s\n",strsignal(sig));
}

int main(int argc, const char * argv[])
{
	int count = 0;
	sigset_t sigmask,origmask;
	struct sigaction act;
	//sigsuspend()

	act.sa_handler = myhandler;
	act.sa_flags = 0;
	sigemptyset(&(act.sa_mask));

	sigaction(SIGCONT,&act,NULL);

	sigemptyset(&sigmask);
	sigaddset(&sigmask,SIGCONT);
	sigprocmask(SIG_BLOCK, &sigmask, &origmask);
	for(;;)
	{
		count ++;
		printf("%d\n",count);
		if(count == 3)
			sigprocmask(SIG_SETMASK,&origmask,NULL);
		pause();
	//	sleep(10);
	}
	return 0;

}
