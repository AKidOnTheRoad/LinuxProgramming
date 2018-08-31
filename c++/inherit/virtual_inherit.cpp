#include <iostream>


using namespace std;

class Box {
	public:
		Box(int m_a = 0, int m_b = 0)
		{
			a = m_a;
			b = m_b;
		}

		~Box(){}

	private:
		int a;
		int b;
};

class Len {
	public:
		Len(int m_a = 0, int m_b = 0)
		{
			aa = m_a;
			bb = m_b;
		}

		~Len(){}

	private:
		int aa;
		int bb;
};

class Square : virtual public Box/*, virtual public Len*/ {
	public:
		Square(int m_a, int m_b, int m_c):Box(m_a, m_b)/*, Len(m_a, m_b)*/
		{
			c = m_c;
		}

		~Square(){}

	private:
		int c;
};

class A{};
class B{};
class C : virtual public A, virtual public B {};

class AA{};
class BB:virtual public AA {};
class CC:virtual public AA {};
class DD:public BB, public CC {};

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
	Square squ(10, 20, 30);//子类需要定义一个虚指针，指向虚表，那么就会多存在一个指针的空间
	cout << "squ: " << sizeof(squ) << endl;

	Box box(10,20);
	cout << "box: " << sizeof(box) << endl;

	cout << "A: " << sizeof(A) << endl;
	cout << "B: " << sizeof(B) << endl;
	cout << "C: " << sizeof(C) << endl;//不同编译器对于虚继承的多继承的类的大小，会差对应个虚指针的大小

	cout << "AA: " << sizeof(AA) << endl;
	cout << "BB: " << sizeof(BB) << endl;
	cout << "CC: " << sizeof(CC) << endl;
	cout << "DD: " << sizeof(DD) << endl;
	return 0;
}
