#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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
	/*
	struct sigaction sa;
	if (sigaction(SIGTSTP, NULL,&sa) == -1)
	{
		printf("sigaction error!!!\n");
		return -1;
	}

	printf("mask:%x\n",sa.sa_mask);

	pause();
	*/

	pid_t pid = 0;
	pid = fork();

	switch(pid) {
	case -1:
		printf("error\n");
		break;

	case 0:
		printf("This is a child.\n");
		sleep(1);
		execl("/bin/echo", "echo", "12", NULL);
		sleep(2);
		exit(0);
		break;

	default:
		if (setpgid(pid, pid) < 0) {
			printf("setpgid error!!!\n");
		}
		printf("modify grpid.\n");
		sleep(2);
		if (setpgid(pid, pid) < 0) {
			printf("setpgid error!!!\n");
		}
		break;
	}
	
	wait(NULL);
	return 0;
}
