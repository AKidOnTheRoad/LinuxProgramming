#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
	const int sz = 10;
	std::vector<int> vInt;

	srand(time(NULL));

	for (int i = 0; i != sz; i++) {
		vInt.push_back(rand()%100);
		std::cout << vInt[i] << " ";
	}
	std::cout << std::endl;

	auto it = vInt.cbegin();
	int a[vInt.size()];

	for (auto &val : a) {
		val = *it;
		std::cout << val << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << a[0] << std::endl;
	return 0;
}
