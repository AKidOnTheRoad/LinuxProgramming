#include <iostream>

using namespace std;

template <unsigned u1, unsigned u2>
void print(ostream& out, const char (&p1)[u1], const char (&p2)[u2])
{
	out << *p1 << *p2;
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
	print(cout, "asd", "qwe");
	return 0;
}
