/***************************************************************************
  > File name:      test.c
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2017-12-26 20:15:29 weeks:52
***************************************************************************/
#include "test.h"

int fun(int*op1,int *op2)
{
	printf("op1:%d \n",*op1);

	return (*op1 + *op2);
}
/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
int main(void)
{
	int op1 = 1, op2 =2;
	int buf;

 /* UNUSED(op1);
  */
	UNUSED(op1);

	char *strmap = malloc(sizeof(char) *20);
	sprintf(strmap,"[%ld,'%u.%u.%u.%u']",(long)123456,10,90,11,22);

	printf("%s\n",strmap);
	free(strmap);
	strmap = NULL;
	

	printf("please input the number:\n");
	scanf("%d",&buf);
	printf("buf:%d\n",buf);

 return 0;
}
