
#include <iostream>
#include <sstream>
#include <vector>

class PersonInfo {
	public:
		std::string name;
		std::vector<std::string> phones;
};

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-11 15:02:17 weeks:32
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	std::string line, word;
	std::vector<PersonInfo> people;

	while(getline(std::cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for(const auto &p : people) {
		std::cout << p.name  << " ";
		for (const auto &m : p.phones)
			std::cout << m << " ";
		std::cout << std::endl;
	}
	return 0;
}
