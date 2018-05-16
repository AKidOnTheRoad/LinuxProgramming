#include <stdio.h>

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
	int fd = (int)(*argv[1]);
	printf("1fd:%d\n",fd);
	sync();
	write(fd, "1234\n", 5);
	write(fd, "bala\n", 5);
	write(fd, "1234\n", 5);
	close(fd);
	return 0;
}
