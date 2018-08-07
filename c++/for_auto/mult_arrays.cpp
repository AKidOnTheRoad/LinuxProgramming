#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
	int mult_array[3][4];
	srand(time(NULL));
/*
	for (auto i = std::begin(mult_array); i != std::end(mult_array); ++i) {
		for (auto m = std::begin(*i); m != std::end(*i); ++m) {
			*m = rand()%10;
			std::cout << *m << " ";
		}
	}
	std::cout << std::endl;
*/
	for (auto &i : mult_array) {
		for (auto &m: i) {
			m = rand()%10;
		}
	}
	std::cout << mult_array[0][0] << " " << mult_array[1][0] << std::endl;
	return 0;
}
