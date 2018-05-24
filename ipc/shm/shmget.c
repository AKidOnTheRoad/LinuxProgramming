#include "shm.h"

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
	key_t key;
	int shmid = 0;
	char *shmaddr;
	char buf[MaxSize];
	key = ftok(TemplateFile, 'a');
	shmid = shmget(key, 0, 0);
	if (shmid < 0) {
		perror("shmget");
		return -1;
	}

	shmaddr = shmat(shmid, NULL, 0);
	if (shmaddr == NULL) {
		perror("shmat");
		return -1;
	}

	memcpy(buf, shmaddr, sizeof("I Love China!"));

	printf("buf:%s\n", buf);
	shmdt(shmaddr);


	return 0;
}
