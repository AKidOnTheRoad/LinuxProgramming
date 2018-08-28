#include <iostream>

using namespace std;
/////不同编译器对格式要求不一样，对于g++来说必须要先声明模版类和模板函数
template <typename T>
class Box;

template <typename T>
ostream& operator<<(ostream& out, Box<T> &b1);
/////


template <typename T> 
class Box {
	friend ostream& operator<<<T> (ostream& out, Box &b1);
	public:
		Box(T a, T b);
		~Box(){};
		Box operator+(Box &b1);
	private:
		T a;
		T b;
};

template <typename T>
Box<T>::Box(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
Box<T> Box<T>::operator+(Box<T> &b1)
{
	Box tmp(a + b1.a, b + b1.b);
	return tmp;
}

template <typename T>
ostream& operator<<(ostream& out, Box<T> &b1)
{
	out << "a: " << b1.a << "b: " << b1.b << endl;	
	return out;
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
	Box<int> box(12, 34);
	cout << box;
	Box<int> box1(10, 20);
	Box<int> tmp = (box+box1);//重载+号运算符

	cout << tmp;//重载输出运算符
	return 0;
}
