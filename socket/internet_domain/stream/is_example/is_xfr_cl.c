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
	if (connect(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("connect");
		return -1;
	}

	while((numRead = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
		if (send(sfd, buf, numRead, 0) != numRead) {
			perror("read");
			return -1;
		}
	}
	close(sfd);

	return 0;
}
