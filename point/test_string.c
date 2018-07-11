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
	char *str = NULL;
	char *str1 = NULL;

	str = "abcd";
	str1 = str;

	printf("str:%p str1:%p\n", str, str1);

	str = "mn";

	printf("str:%p str1:%p\n", str, str1);

	return 0;
}
