
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>


#define Tempelate "../Makefile"
/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-05-19 13:38:38 weeks:20
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
	int msgid;
	key = ftok(Tempelate, 'a');

	while ((msgid = msgget(key, IPC_CREAT|IPC_EXCL|0664)) == -1) {
		if (errno == EEXIST) {
			printf("ipc msg has existed.\n");
			msgid = msgget(key, 0);

			msgctl(msgid, IPC_RMID, NULL);
		}
	}
	printf("msgid:%d\n", msgid);

	return 0;
}
