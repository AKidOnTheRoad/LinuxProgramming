#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	int fd = open("test.txt", O_CREAT|O_RDWR|O_APPEND|O_TRUNC, 0664);
	pid_t childPid;

	fcntl(fd, F_SETFD, 0);
	printf("fd:%d\n", fd);
	write(fd,"just for a checking.\n'", 30);

	 childPid = fork();

	 if (childPid < 0)
	 {
		 perror("fork");
		 return -1;
	 }

	 if(childPid == 0)
	 {
		 printf("fd:%d\n",fd);
		int ret = execl("./test", "./test", (char *)&fd, (char*)NULL);
	//	write(fd, "What the fuck.\n", 20);
		exit(0);
	 }

	wait(NULL);
//	 waitpid(childPid,NULL,0);

		write(fd, "shit.\n", 7);

		close(fd);
	return 0;
}
