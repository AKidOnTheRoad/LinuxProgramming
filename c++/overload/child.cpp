
#include <iostream>

using namespace std;

class Parent {
	public:
		virtual ~Parent()
		{
			cout << "Parent destructor" << endl;
		}
		virtual void func()
		{
			cout << "func" << endl;
		}
		//重载只发生在同一类中
		//子类无法重载父函数
		void func(int a)
		{
			cout << "func argv:a" << endl;
		}

		void func(int a, int b)
		{
			cout << "func argv:a b" << endl;
		}
};

class Child : public Parent {
	public:
		~Child()
		{
			cout << "Child destructor" << endl;
		}
		void func(int a)  // 父类和子类中不使用virtual则为重定义
			//使用virtual，则为重写，即多态
		{
			cout << "child func argv a" << endl;
		}

		void func(int a, int b)
		{
			cout << "Child func argv a b" << endl;
		}
	

};
/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-18 19:15:24 weeks:33
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	/*
	Parent p;
	p.func();
	p.func(1);
	p.func(1,2);

	Child c;
	c.func(1);
*/
	Parent *p1 = new Child;//通过基类指针释放父类和子类的资源
	
	delete p1;
	return 0;
}
