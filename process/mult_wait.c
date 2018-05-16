#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static int idata = 11;

int main(int argc, const char * argv[])
{
	int numDead;
	int j, childPid;
	int childPid_bak = 0;
	setbuf(stdout, NULL);
	for (j = 1; j < argc; j++)
	{
		switch(childPid_bak = fork())
		{
		case -1:
			perror("fork");
			break;
		case 0:
			printf("child %d started with PID %ld,sleeping %s seconds\n", j, (long)getpid(), argv[j]);
			sleep(atoi(argv[j]));
			return 3;
			break;
		default:
			write(1, "hello\n", 6);
			printf("childPid=%d\n",childPid_bak);
			break;
		}
	}
	numDead = 0;
	for(;;){
		childPid = wait(NULL);
		if (childPid == -1) {
			if (errno = ECHILD) {
				printf("No more children - bye\n");
				exit(0);
			} else {
				exit(1);
			}
		}

		numDead++;
		printf("child PID %ld (numDead=%d)\n", (long)childPid, numDead);
	}
	wait(NULL);
}
