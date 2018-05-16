/***************************************************************************
  > File name:      fileio.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2018-03-09 19:37:19 weeks:10
***************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


char *str_malloc()
{
	char * pPoint = malloc(100);
	return pPoint;
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
	int ReadFd,WriteFd;
	char buf[512];
	int numbers;
#if 0
	if (argc < 3)
	{
		//printf("loss argcment!!!\n");
		return -1;
	}
	if ((ReadFd = open(argv[1],O_RDONLY)) < 0)
	{
		printf("open failed!!!\n");
		return -1;
	}
	
	if ((WriteFd = open(argv[2],O_CREAT|O_RDWR|O_TRUNC)) < 0)
	{
		printf("open failed!!!\n");
		return -1;
	}

	while ((numbers = read(ReadFd,buf,512)) > 0)
	{
		write(WriteFd,buf,numbers);
	}


	close(ReadFd);
	close(WriteFd);
#endif
	struct termios flag;
	tcgetattr(0,&flag);
	flag.c_lflag &= ~(ECHO|ICANON);
	tcsetattr(0,TCSANOW,&flag);

	while (read(0,buf,1) > 0)
	{
		//write(1,buf,1);
	}
#if 0
	char * pPoint = NULL;
	printf("pPoint = %p\n",pPoint);
	pPoint = str_malloc();
	printf("pPoint = %p\n",pPoint);
	*pPoint = 123;
	printf("*pPoint = %d\n", *pPoint);
	free(pPoint);
#endif
	return 0;
}
