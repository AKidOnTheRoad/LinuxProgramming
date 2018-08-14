#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <iterator>

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
	std::multimap<std::string, int> mmap;
	mmap.insert(std::make_pair("ken", 10));//按照字典顺序进行排列 ASCII序列
	mmap.insert(std::make_pair("Jen", 12));
	mmap.insert(std::make_pair("Aina", 14));

	std::cout << mmap.find("ken")->second << std::endl;

	for (std::multimap<std::string, int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	return 0;
}
