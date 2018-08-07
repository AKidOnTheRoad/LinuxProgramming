#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
	std::string cur_str, prev_str;
	bool flag = false;

	while (std::cin >> cur_str) {
		if (!isupper(cur_str[0]))
			continue;

		if (prev_str == cur_str) {
			flag = true;
			std::cout << "The first input is tha same as the second input" << std::endl;
			break;
		}
		prev_str = cur_str;
	}

	if (flag)
		std::cout << cur_str << std::endl;

	return 0;
}
