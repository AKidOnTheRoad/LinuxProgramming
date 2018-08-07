#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> str;
	std::string str1;
	std::cout << "Pls input somr string:" << std::endl;

	for (int i = 0; i != 10; i++) {
		std::cin >> str1;
		str.push_back(str1);
	}

	for (auto cn : str) {
		std::cout << cn << " ";
	}
	std::cout << std::endl;

	return 0;

}
