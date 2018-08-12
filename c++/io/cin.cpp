
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-11 14:25:36 weeks:32
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, const char *argv[])
{

	std::ifstream in("./debug.txt");
	std::vector<std::string> vec;
	std::string str;
	if (in) {
		//while(getline(in, str)) {
		while(in >> str) {
			vec.push_back(str);
		}
	}

	for(auto p : vec)
		std::cout << p << std::endl;

	in.close();

	return 0;
}
