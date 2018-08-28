#include <iostream>

using namespace std;

template <typename T> 
	class A {
		public:
			A(T a) 
			{
				this->a = a;
			}
			void print()
			{
				cout << "a: " << a << endl;
			}
		protected:
			T a;
	};

//在类模板的派生过程中，父类模板必须显式声明并调用
template <typename T>
	class B : public A<T> {
		public:
			B(T b, T a) : A<T>(a)//调用父类初始化参数列表
			{
				this->b = b;
			}
			void print()
			{
				cout << "b: " << b << endl;
			}

		protected:
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
	B<int> b1(10, 20);
	b1.print();//调用B的print函数
	b1.A::print();//调用A的print函数
	//b1.A<int>::print(); //两种形式调用都可以
	return 0;
}
