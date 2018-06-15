#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
int main(int argc, char *argv[])
{
	int opt, xfnd;
	char *pstr;

	xfnd = 0;
	pstr = NULL;

	while ((opt = getopt(argc, argv, ":p:x")) != -1) {
		printf("opt =%3d (%c); optind = %d", opt, printable(opt), optind);
		if (opt == '?' || opt == ':') 
			printf("; optopt = %3d (%c)", optopt, printable(optopt));
		printf("\n");

		switch (opt) {
		case 'p': pstr = optarg;  		break;
		case 'x': xfnd++; 				break;
		case ':': printf("missing argument"); exit(0);
		case '?': printf("Unrecognized option"); exit(0);
		}
	}

	return 0;
}
