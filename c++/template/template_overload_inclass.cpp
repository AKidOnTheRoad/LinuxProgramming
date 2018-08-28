#include <iostream>

using namespace std;
//所有成员函数或者类的友元函数都在类的内部进行声明和定义
template <typename T> 
class Box {
	friend ostream& operator<< (ostream& out, Box &b1)
	{
		out << "a: " << b1.a << "b: " << b1.b << endl;	
		return out;
	}
	public:
		Box(T a, T b)
		{
			this->a = a;
			this->b = b;
		}
		~Box(){};
		Box operator+(Box &b1)
		{
			Box tmp(a + b1.a, b + b1.b);
			return tmp;
		}
	private:
		T a;
		T b;
};

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
	Box<int> box(12, 34);
	cout << box;
	Box<int> box1(10, 20);
	Box<int> tmp = (box+box1);//重载+号运算符

	cout << tmp;//重载输出运算符
	return 0;
}
