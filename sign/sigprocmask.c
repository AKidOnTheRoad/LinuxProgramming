#include <stdio.h>
#include <signal.h>

int main(int argc, const char *argv[])
{
	sigset_t blockSet, prevMask;

	//sigemptyset(&blockSet);
	//sigaddset(&blockSet,SIGINT);

	sigfillset(&blockSet);

	if (sigprocmask(SIG_BLOCK, &blockSet, &prevMask) == -1)
		perror("sigprocmask");

	for(;;)
		pause();

}
