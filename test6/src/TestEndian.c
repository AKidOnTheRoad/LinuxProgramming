/***************************************************************************
  > File name:      TestEndian.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2018-02-01 16:31:30 weeks:05
***************************************************************************/
#include "TestEndian.h"

int testEndian(void)
{
	myUn tmpUn;
	tmpUn.b = 0xAA01;

	return tmpUn.a;
}

int modify(int *val)
{
	*val = 12;
	modifyOnce(val);
	return 0;
}


int modifyOnce(int *val)
{
	*val = 34;
	return 0;
}

int debug(int a, int b)
{
	a = a+b;
	return 0;
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
	int testVal = 0;
	testVal = testEndian();

	if (testVal == 1)
		printf("Little Endian!!!\n");
	else
		printf("Big Endian!!!\n");

	int tVal;
	modify(&tVal);

	printf("%d\n",tVal);

	int a = 1, b = 5;
	debug(a,b);
	printf("a:%d\n",a);
	return 0;
}
