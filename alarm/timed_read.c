#include <stdio.h>
#include <signal.h>
#include <errno.h>

#define BUF_SIZE 200

void handler(int sig)
{
	printf("Caught signal!!\n");
}

int main(int argc,const char *argv[])
{
	struct sigaction sa;
	char buf[BUF_SIZE];
	int numRead;
	int savedErrno;

	sa.sa_flags = 0;
	sigemptyset(&(sa.sa_mask));
	sa.sa_handler = handler;
	sigaction(SIGALRM,&sa,NULL);

	alarm(10);
	numRead = read(1,buf,BUF_SIZE);

	savedErrno = errno;
	alarm(0);
	errno = savedErrno;

	if (numRead == -1)
	{
		if (errno == EINTR)
		{
			printf("Read time out!\n");
		}
		else
		{
			printf("read error!!!\n");
			return -1;
		}
	}
	else
		printf("read success %.*s\n", numRead,buf);

	return 0;

}
