#include <stdio.h>
#include <pthread.h>
#include <string.h>

static int glob = 0;

void * threadFuc(void * arg)
{
	int count = *((int *)arg);
	int i = 0, loc = 0;
	for (i = 0; i < count; i++) {
		loc = glob;
		loc++;
		glob = loc;
	}

	return NULL;
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
	if (argc < 2 || strcmp(argv[1], "--help") == 0) {
		printf("lose arguments!!!\n");
		return -1;
	}

	pthread_t t1, t2;
	int count = atoi(argv[1]);
	pthread_create(&t1, NULL, threadFuc, (void*)&count);
	pthread_create(&t2, NULL, threadFuc, (void*)&count);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
