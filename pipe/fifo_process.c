#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
#define TempFifo1 "/tmp/myfifo1"
#define TempFifo2 "/tmp/myfifo2"

int main(int argc, const char *argv[])
{
	int  num = 0;
	char buf[64] = {0};
	int fd1, fd2;
	mkfifo(TempFifo1,0664);
	mkfifo(TempFifo2,0664);

	switch(fork()) {
	case -1:
		printf("fork() error!!!\n");
		return -1;
		break;
	case 0:
		fd1 = open(TempFifo1, O_RDONLY);
		fd2 = open(TempFifo2, O_WRONLY);

		//close(pipefd1[1]); //close unuse write in pipe 1
		//close(pipefd2[0]); //close unuse read in pipe 2
		int i = 0;
		while(1) {
			read(fd1, buf, sizeof(buf));
			if (strncmp(buf, "quit", 4) == 0) {
				close(fd1);
				close(fd2);
				exit(0);
			}

			for(i = 0; i < strlen(buf); i++) {
				buf[i] = toupper(buf[i]);
			}

			printf("This is a child:\n");
			write(fd2, buf, strlen(buf)+1);

		}
		break;
	default:
	//	close(pipefd1[0]); //close unuse read in pipe 1
	//	close(pipefd2[1]); //close unuse write in pipe 2
		fd1 = open(TempFifo1, O_WRONLY);
		fd2 = open(TempFifo2, O_RDONLY);
		break;
	}

	while(1) {
		fgets(buf, sizeof(buf), stdin);
		write(fd1, buf, strlen(buf)+1);
		memset(buf, 0, sizeof(buf));	

		printf("This is a parent:\n");
		if (read(fd2, buf, sizeof(buf)) == 0) 
		{

			close(fd1);
			close(fd2);
			unlink(TempFifo1);
			unlink(TempFifo2);
			return 0;
		}

		write(1, buf, strlen(buf)+1);
	}

	return 0;
}
