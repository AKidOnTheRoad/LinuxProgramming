#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	printf("Hello World!!!\n");
	write(1,"1231\n",5);
	if (fork() == -1)
		return -1;

	_exit(0);
}
