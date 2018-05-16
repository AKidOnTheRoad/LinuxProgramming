#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
	pid_t childPid;
	childPid = fork();

	setbuf(stdout, NULL);

	if (childPid == 0) {
		printf("I am a child process.My ppid:%d\n",getppid());
		sleep(7);
		printf("I am a child process that no one owns.My ppid:%d\n",getppid());
	}

	return 0;
}
