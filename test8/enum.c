#include <stdio.h>

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/


enum abc {
	IO_Rd = 0,
#define IO_Rd IO_Rd
	IO_Wr = 1,
//#define IO_Wr IO_Wr
};

int main(int argc, const char *argv[])
{
#ifdef IO_Rd
		printf("%s\n", "123");
#endif
	return 0;
}
