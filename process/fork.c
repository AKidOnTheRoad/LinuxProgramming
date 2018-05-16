#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int idata = 11;

int main(int argc, const char * argv[])
{
	int istack = 22;
	pid_t childPid,pid;
	int status;

	setbuf(stdout, NULL);

	switch(childPid = fork())
	{
		case -1:
			perror("fork");
			break;
		case 0:
			pid = fork();
			if (pid == 0){
				printf("I am a grandson.my pid:%d\n",getppid());
				sleep(2);
				printf("I am a grandson.my pid:%d\n",getppid());
				printf("I am a grandson.my pid:%d\n",getppid());
				printf("I am a grandson.my pid:%d\n",getppid());
				for(;;)
					;
			} else {
				sleep(1);
				printf("I am a father.I exited.\n");
				exit(0);
			}
			break;
		default:
			printf("I am a grandfather.\n");
			sleep(5);
			wait(&status);
			printf("This is a parent process.   status:%d\n",(status>>8));
			break;
	}
	//printf("PID:%ld %s idata:%d istack:%d\n",getpid(),(childPid == 0)?"child":"parent",idata,istack);
	return 0;
}
