#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>

struct MyException: public std::exception 
{
	const char *what() const throw() {
		return "C++ Exception";
	}
};

int main(int argc, char *argv[])
{
	std::string cur_str;

	while (std::cin >> cur_str) {
		if (cur_str == "quit" || cur_str == "Quit")
			break;
		try {
		if (!isupper(cur_str[0]))
			throw MyException();
			//throw "Today is very hard."; 					   #2
			//throw std::runtime_error ("Today is not good."); #1
		//} catch (const char *err) {  						   #2
		//} catch (std::runtime_error err) { 				   #1
		} catch (MyException& err) {
			std::cout << err.what() << std::endl;
		} catch (...) {
			std::cout << "error" << std::endl;
		}
	}
	return 0;
}
