
#include <iostream>
#include <forward_list>
#include <string>


void insert_mem(std::forward_list<std::string>& strlist, const std::string &str1, const std::string &str2)
{
	auto prev = strlist.before_begin();
	auto curr = strlist.begin();
	bool flag = false;

	while(curr != strlist.end()) {
		if(*curr == str1) {
			curr = strlist.insert_after(curr, str2);
			flag = true;
		}
		prev = curr;
			curr++;
			std::cout << "loop" << std::endl;
	}
	if(!flag)
		curr = strlist.insert_after(prev, str2);

}
/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-12 10:56:44 weeks:32
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	std::forward_list<std::string> llist = {"string", "abcdef", "world"};
	insert_mem(llist, "string", "bigstr");

	std::cout << "insert success" << std::endl;
	for(auto &p : llist)
		std::cout << p << " ";

	std::cout << std::endl;

	return 0;
}
