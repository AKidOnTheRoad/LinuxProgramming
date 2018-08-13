#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

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
	std::vector<std::string> vec;
	std::string str;

	std::ifstream in(argv[1]);
	if(!in){
		std::cerr << "open fail" << std::endl;
		return -1;
	}
	
	while(in >> str)
		vec.push_back(str);

	std::cin >> str;
	std::cout << count(vec.begin(), vec.end(), str);
	return 0;
}
