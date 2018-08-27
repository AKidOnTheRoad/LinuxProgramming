#include <iostream>
#include <string>
using namespace std;

template<typename T, typename... Args>
	void test(const T &t, const Args& ... rest)
	{
		cout << "Args: " << sizeof...(Args) << "\t";
		cout << "rest: " << sizeof...(rest) << endl;
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
	int i =0;
	double d = 3.14;
	string s = "how";

	test(i);//have no argument
	test(d, i, "123");//have two arguments
	test(s, i, "123", i);//have three arguments
	return 0;
}
