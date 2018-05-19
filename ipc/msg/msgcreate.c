#include "msg.h"

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-05-19 15:29:54 weeks:20
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, const char *argv[])
{
	key_t key;
	int opt, keyFlag = 0, flags = 0;
	int perms = 0, msgid = 0;
	while ((opt = getopt(argc, argv, "cf:px")) != -1) {
		switch (opt) {
		case 'c':
			flags |= IPC_CREAT;
			break;
		case 'f':
			key = ftok(optarg, 'a');
			keyFlag = 1;
			break;
		case 'p':
			key = IPC_PRIVATE;
			keyFlag = 1;
			break;
		case 'x':
			flags |= IPC_EXCL;
			break;
		}
	}

	if (keyFlag != 1) {
		printf("error!!!\n");
		return -1;
	}

	perms = (argc == optind) ? (S_IRUSR | S_IWUSR) : atoi(argv[optind]);
	msgid = msgget(key, flags | perms);
	if(msgid < 0)
		printf("msgget error!!!\n");
	return 0;
}
