#include <iostream>
#include <memory>
#include <vector>

using namespace std;

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
	shared_ptr<int> p = make_shared<int>(42);
	auto m = make_shared<int> (42); //p 和 m并不指向同一个对象，具体可看addr的打印
	//auto m = p;

	*p = 53;

	cout << *m << endl;
	cout << "m:" << m << endl;
	cout << "p:" << p << endl;

	vector<int> vec;
	vec.push_back(12);

	shared_ptr<vector<int>> sp = make_shared<vector<int>>(vec);
	for (auto ptr : *sp)
		cout << ptr << endl;

	cout << (*sp)[0] << endl;
	return 0;
}
