#include <iostream>
#include <string>
#include <cstring> 

using namespace std;

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
	const char *c1 = "Hello";
	const char *c2 = "World";
	char *dst = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(dst, c1);
	strcat(dst, c2);

	cout << dst << endl;

	string s1 = "Hello";
	string s2 = "World";

	strcpy(dst, (s1+s2).c_str());
	cout << dst << endl;
	delete [] dst;
	return 0;
}
