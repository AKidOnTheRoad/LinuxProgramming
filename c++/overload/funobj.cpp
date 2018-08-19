
#include <iostream>
using namespace std;

class Tree {
	public:
		Tree(int age = 100):treeAge(age) {}
		~Tree() {}
		void operator()()
		{
			cout << treeAge << endl;
		}
	private:
		int treeAge;
};
/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-18 15:56:50 weeks:33
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	Tree tree;
	tree();
	return 0;
}
