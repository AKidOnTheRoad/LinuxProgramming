#include "weak_ptr.h"

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
	strBlob b1;//构造函数
	strBlob b2 = { "a", "an", "the"};//构造函数 列表初始化
	b1 = b2;
	b2.push_back("about");
	cout << b2.size() << endl;

	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	const strBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}
