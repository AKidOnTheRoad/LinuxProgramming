#include <iostream>
#include <vector>

int count(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int target)
{
	int count = 0;
	for(auto head = begin; head != end; head++) {
		if(*head == target)
			count++;
	}

	return count;
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
	int val = 0;
	std::vector<int> vec;
	while(std::cin >> val)
		vec.push_back(val);
	std::cout << "Input the searching val:" << std::endl;
	std::cin >> val;
	std::cout << count(vec.begin(), vec.end(), val) << std::endl;
	return 0;
}
