
#include  "msg.h"

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-05-19 16:09:33 weeks:20
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, const char *argv[])
{

	msg myMsg;
	int msgid, opt, type;
	int flags = 0;

	while ((opt = getopt(argc, argv, "et:n")) != -1) {
		 switch (opt) {
		 case 'e':
			 flags |= MSG_NOERROR;
			 break;
		 case 'n':
			 flags |= IPC_NOWAIT;
			 break;
		 case 't':
			 type = atoi(optarg);
			 break;
		 }
	}
	
	if ((argc < optind + 1) || (argc > optind + 2)) {
		printf("error about arguments.\n");
		return -1;
	}

	msgid = atoi(argv[optind]);
	printf("tupe:%d\n",type);
	msgrcv(msgid, &myMsg, MAX_MTEXT, type, flags);

	printf("recv message:%s\n",myMsg.mtext);
	return 0;
}
