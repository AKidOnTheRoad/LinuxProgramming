
#include <iostream>
#include <vector>

/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-12 12:51:06 weeks:32
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	int val;
	std::vector<int> vec;
	std::cout << "size: "  << vec.size() << " capacity: " << vec.capacity() << std::endl;
	
	std::cin >> val;
	vec.push_back(val);
	std::cout << "size: "  << vec.size() << " capacity: " << vec.capacity() <<  std::endl;
	return 0;
}
