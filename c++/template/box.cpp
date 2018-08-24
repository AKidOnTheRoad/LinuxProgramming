#include <iostream>

using namespace std;

template <typename T> class Box {
	public:
		Box(T len, T wid)
		{
			length = len;
			width = wid;
		}
		~Box(){}
		T getSize()
		{
			return width*length;
		}
	private:
		T length;
		T width;
};

template <typename T>
void myswap(T& src, T& dst)
{
	T tmp;
	tmp = src;
	src = dst;
	dst = tmp;
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
	Box<int> box1(10,20);//类模板在实例化的过程中，不支持隐式声明，必须显式的指明类型
	cout << "size: " << box1.getSize() << endl;

	Box<double> box2(5.5, 10.5);
	cout << "size: " << box2.getSize() << endl;

	int a = 10, b = 20;
	myswap(a, b);//函数模版支持显式声明和隐式声明两种模式
	cout << "a: " << a << "b: " << b << endl;

	myswap<int>(a, b);
	cout << "a: " << a << "b: " << b << endl;
	return 0;
}
