
#include "msg.h"

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-05-19 16:31:25 weeks:20
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, const char *argv[])
{
	int msgid, opt, msgLen = 0, flags = 0;
	msg myMsg;

	while ((opt = getopt(argc, argv, "n")) != -1) {
		if (opt == 'n')
			flags |= IPC_NOWAIT;
	}

	if (argc < optind + 2 || argc > optind + 3) {
		printf("error arguments!!!\n");
		return -1;
	}
	msgid = atoi(argv[optind]);
	myMsg.mtype = atoi(argv[optind + 1]);

	if (argc > optind + 2) {
		msgLen = strlen(argv[optind + 2]) + 1;

		memcpy(myMsg.mtext, argv[optind + 2], msgLen);
	}

	msgsnd(msgid, &myMsg, msgLen, flags);
	return 0;
}
