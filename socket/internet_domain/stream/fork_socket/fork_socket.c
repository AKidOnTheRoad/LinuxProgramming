#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

static int count = 0;

static void handler(int sig)
{
	while(waitpid(-1, NULL, WNOHANG) > 0) {
		count--;
		continue;
	}
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
	pid_t pid = 0;
	int i = 0;

	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGCHLD, &sa, NULL);

	for (;;) {
		count++;
		switch(fork()) {
		case -1:
			perror("fork");
			break;
		case 0:
			if (count > 10)
				exit(0);
			for(;;) {
				printf("childnum:%d\n", count);
				sleep(count);
			}
			break;
		default:
			break;
		}
	}

	return 0;
}
