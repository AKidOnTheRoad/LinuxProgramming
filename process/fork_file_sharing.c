#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, const char * argv[])
{
	int fd, flags;
	char template[] = "/tmp/testXXXXXX";

	setbuf(stdout, NULL);
	fd = mkstemp(template);
	if (fd == -1)
	{
		perror("mkstemp");
		return -1;
	}

	printf("File offset before fork():%d\n",lseek(fd, 0 ,SEEK_CUR));
	flags = fcntl(fd, F_GETFL);
	printf("O_APPEND flag before fork() is %s\n", (flags&O_APPEND) ? "on" : "off");

	switch(fork())
	{
	case -1:
		perror("fork");
		break;

	case 0:
		if (lseek(fd, 1000, SEEK_SET) < 0)
		{
			perror("lseek");
			return -1;
		}
		flags = fcntl(fd, F_GETFL);
		flags |= O_APPEND;
		fcntl(fd, F_SETFL, flags);

		break;

	default:
		wait(NULL);
		printf("File offset after fork():%d\n",lseek(fd, 0 ,SEEK_CUR));
		flags = fcntl(fd, F_GETFL);
		printf("O_APPEND flag after fork() is %s\n", (flags&O_APPEND) ? "on" : "off");
		break;
	}
	return 0;
}
