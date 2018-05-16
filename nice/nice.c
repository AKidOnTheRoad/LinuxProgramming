#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/resource.h>

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
int main(int argc, char *argv[])
{
	int opt, prio, num;

	if (argc < 2) {
		errno = 0;
		prio = getpriority(PRIO_PROCESS, 0);
		if (prio == -1 && errno !=0)
			return -1;
		printf("Nice Value:%d\n", prio);
	} else {
		while ((opt = getopt(argc,argv,"n:")) != -1)
		{
			switch(opt) {
			case 'n':
				printf("optind:%d\n",optind);
				num = atoi(optarg);
				if (setpriority(PRIO_PROCESS, 0, num) < -1) {
					return -1;
				}
				errno = 0;
				prio = getpriority(PRIO_PROCESS, 0);
				if (prio == -1 && errno !=0)
					return -1;
				printf("Nice Value:%d\n", prio);
				break;
			default:
				break;
			}
		}
	}
	return 0;
}
