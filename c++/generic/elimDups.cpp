#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void outPut(std::vector<std::string>&vec)
{
	for (auto p : vec)
		std::cout << p << " ";
	std::cout << std::endl;
}

int elimDups(std::vector<std::string> &vec)
{
	outPut(vec);

	sort(vec.begin(), vec.end());//排序

	auto end_unique = unique(vec.begin(), vec.end());//返回最后一个不唯一的元素的下一位置

	vec.erase(end_unique, vec.end());//删除两个迭代器之间的元素  左闭右开

	outPut(vec);

	return 0;
}

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
	while(std::cin >> str) {
		vec.push_back(str);
	}

	elimDups(vec);


	return 0;
}
