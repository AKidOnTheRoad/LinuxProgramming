#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

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
	std::ifstream in(argv[1]);
	if(!in) {
		std::cout << "error";
		return -1;
	}

	std::istream_iterator<std::string> str_in(in), eof;
	std::ostream_iterator<std::string> str_cout(std::cout, "\n");

	std::vector<std::string> vec;

	while(str_in != eof)
		vec.push_back(*str_in++);

	for (auto &p :vec)
		*str_cout++ = p;

	return 0;
}
