#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
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
	int pipefd1[2], pipefd2[2], num = 0;
	char buf[64] = {0};
	pipe(pipefd1);
	pipe(pipefd2);

	switch(fork()) {
	case -1:
		printf("fork() error!!!\n");
		return -1;
		break;
	case 0:
		close(pipefd1[1]); //close unuse write in pipe 1
		close(pipefd2[0]); //close unuse read in pipe 2
		int i = 0;
		while(1) {
			read(pipefd1[0], buf, sizeof(buf));
			if (strncmp(buf, "quit", 4) == 0) {
				close(pipefd1[0]);
				close(pipefd2[1]);
				exit(0);
			}

			for(i = 0; i < strlen(buf); i++) {
				buf[i] = toupper(buf[i]);
			}

			printf("This is a child:\n");
			write(pipefd2[1], buf, strlen(buf)+1);

		}
		break;
	default:
		close(pipefd1[0]); //close unuse read in pipe 1
		close(pipefd2[1]); //close unuse write in pipe 2
		break;
	}

	while(1) {
		fgets(buf, sizeof(buf), stdin);
		write(pipefd1[1], buf, strlen(buf)+1);
		memset(buf, 0, sizeof(buf));	

		printf("This is a parent:\n");
		if (read(pipefd2[0], buf, sizeof(buf)) == 0) 
		{
			return 0;
		}

		write(1, buf, strlen(buf)+1);
	}

	return 0;
}
