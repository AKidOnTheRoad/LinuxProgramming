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
	key = ftok(TemplateFile, 'a');

	if (key < 0) {
		perror("ftok");
		return -1;
	}
	shmid = shmget(key, MaxSize, IPC_CREAT|IPC_EXCL|0664);
	if (shmid < 0) {
		perror("shmget");
		return -1;
	}

	shmaddr = shmat(shmid, NULL, 0);
	if (shmaddr == NULL) {
		perror("shmat");
		return -1;
	}

	memcpy(shmaddr, "I Love China!", sizeof("I Love China!"));

	shmdt(shmaddr);

	sleep(4);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
