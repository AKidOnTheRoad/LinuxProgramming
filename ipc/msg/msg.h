#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_MTEXT 1024
typedef struct {
	int mtype;
	char mtext[MAX_MTEXT];
}msg;

