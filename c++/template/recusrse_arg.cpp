#include <iostream>

using namespace std;

template<typename T> //不可变参数版本函数应该在可变参数版本之前声明并定义，不然会产生compile错误. 
ostream &print(ostream &os, const T &t)
{
	return os << t << endl;
}

template<typename T, typename ...Args>//可变参数模板的格式
ostream &print(ostream &os, const T &t, const Args& ... rest)//可变参数模板函数
{
	os << t << ", ";
	return print(os, rest...);
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
	print(cout, "1", "2", 123);
	print(cout, "errmsg: ", "System crashes.");
	return 0;
}
