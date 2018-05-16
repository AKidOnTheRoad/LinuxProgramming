/***************************************************************************
  > File name:      point_main.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2017-12-06 19:52:38 weeks:49
***************************************************************************/

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
	char *name[] = {
		"abcdef",
		"hello",
		"world"
	};

	char **temp;

	temp = name;
	printf("string:%s\n",*name);
	printf("st:%s str:%s\n",*temp,*temp++);
	return 0;
}
