#include <stdio.h>
#include <stdlib.h>

#define bufSize  1024
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
	int a;
	char *buf = NULL;
	buf = (char *)malloc(bufSize);
	if (buf == NULL) {
		perror("malloc");
		return -1;
	}


	while(1) {
		if (fgets(buf, bufSize, stdin) != NULL) {
			printf("%s",buf);
			if (strncmp(buf, "quit", 4) == 0) {
				break;
			}

		} else {
			continue;
		}

	}
	free(buf);
	return 0;
}
