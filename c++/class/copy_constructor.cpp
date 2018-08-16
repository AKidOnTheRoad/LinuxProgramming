#include <iostream>
#include <string>

using namespace std;

class Employee {
	private:
		static int count;
		string name;
		int id;

	public:
		Employee(){//构造函数
			id = ++count;
		}
		Employee(const string &str) { //重载构造函数
			name = str;
			id = ++count;
		}
		
		Employee(const Employee& emp) { //拷贝构造函数
			name = emp.name;
			id = ++count;
		}

		Employee& operator=(const Employee& emp) { //拷贝赋值运算符
			name = emp.name;
			return *this;
		}
		void print() 
		{
			cout << this->id << this->name << endl;
		}
};

int Employee::count = 0;

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
	Employee dm("zhang"), c, a = dm/*拷贝构造*/;
	dm.print();
	a.print();
	c = a;//拷贝赋值运算
	c.print();
	return 0;
}
