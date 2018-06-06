#include "is_xfr.h"

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
	char buf[128];
	int numRead = 0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(IS_PORT);
	inet_pton(AF_INET, LOOPBACK, &addr.sin_addr);

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

		while((numRead = recv(cfd, buf, sizeof(buf), 0)) > 0) {
			if (write(STDOUT_FILENO, buf, numRead) != numRead) {
				perror("write");
				return -1;
			}
		}
		close(cfd);
	}

	return 0;
}
