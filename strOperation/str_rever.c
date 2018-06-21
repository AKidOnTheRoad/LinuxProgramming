#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void str_rever(char *str, int len) 
{
	char *pStart, *pEnd;
	char tempChar;
	pStart = str;
	pEnd = str + len - 1;
	
	while (pStart < pEnd) {
		tempChar = *pStart;
		*pStart = *pEnd;
		*pEnd = tempChar;
		pStart++;
		pEnd--;
	}

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
	char *str = (char *)malloc(100);
	fgets(str, 100, stdin);

	str_rever(str,strlen(str)-1);

	free(str);
	return 0;
}
