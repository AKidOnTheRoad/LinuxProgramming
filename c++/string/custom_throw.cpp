#include <iostream>
#include <stdexcept>
#include <string>

class Exception : public std::exception {
	public:
		Exception(int errId = 0, const char * errMsg = "")
			:_errId(errId), _errMsg(errMsg){

			}
		virtual const char* what() const throw() {//notice the format about what();
			std::cout << "errId:" << _errId << std::endl;
			std::cout << "errMsg:" << _errMsg.c_str() << std::endl;
			return _errMsg.c_str();
		}

	private:
		int _errId;
		std::string _errMsg;
};

void TestException()
{
	throw Exception(1, "Customize the class exception.");
}
int main(int argc, char *argv[])
{
	try {
		TestException();
	} catch(Exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
