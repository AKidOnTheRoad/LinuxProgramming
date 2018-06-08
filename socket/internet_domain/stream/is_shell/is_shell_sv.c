#include "is_shell.h"

static void handler(int sig)
{
	int savedErr, childPid;
	savedErr = errno;
	while ((childPid = waitpid(-1, NULL, WNOHANG)) > 0) {
		printf("waitpid success pid:%d !!!\n", childPid);
	}

	if (childPid < 0 && errno != ECHILD) {
		perror("waitpid");
		return ;
	}
	errno = savedErr;


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
	int sfd, cfd;
	struct sockaddr_in addr;
	struct sigaction sa;
	char buf[128];
	int numRead = 0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(IS_PORT);
	inet_pton(AF_INET, LOOPBACK, &addr.sin_addr);

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGCHLD, &sa, NULL);


	if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		return -1;
	}

	if (listen(sfd, 5) < 0) {
		perror("listen");
		return -1;
	}

	for(;;) {
		cfd = accept(sfd, NULL, NULL);
		if (cfd < 0) {
			perror("accept");
			return -1;
		}

		int read = 0;
		switch(fork()) {
		case -1:
			perror("fork");
			close(cfd);
			break;
		case 0:
			//buf[read] = '\0';
			if (cfd != STDOUT_FILENO || cfd != STDERR_FILENO) { /*cfd is directed into STDERR_FILENO and STDOUT_FILENO*/
				dup2(cfd,STDERR_FILENO);
				dup2(cfd,STDOUT_FILENO);
				close(cfd);
			}
			while((numRead = recv(STDOUT_FILENO, buf, sizeof(buf), 0)) > 0) {
				read += numRead;
			}
			execl("/bin/sh", "sh", "-c", buf, NULL);
			exit(0);
			break;
		default:
			close(cfd);
			break;
		}
	}

	return 0;
}
