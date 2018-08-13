#include <iostream>

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
	int a = 100;
	auto f = [a](){ return a;};//lambda format [capture list](parameter list) {function body};
	a = 10;
	std::cout << f() << std::endl;

	auto m = [&a](){ return ++a;};
	a =10;
	std::cout << m() << std::endl;

	auto n = [a] () mutable {return ++a;};
	std::cout << n() <<std::endl;
	std::cout << a << std::endl;

	return 0;
}
