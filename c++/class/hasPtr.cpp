#include <iostream>
#include <string>

using namespace std;

class HasPtr {
	public:
		HasPtr(const string &s = string()) : 
			ps(new string(s)), i(0), use(new size_t(1)) {}
		HasPtr(const HasPtr &p) : 
			ps(p.ps), i(p.i), use(p.use) {}//拷贝构造函数
		HasPtr& operator=(const HasPtr&);//拷贝赋值运算符
		HasPtr& operator=(const string&);//拷贝赋值运算符重载
		string& operator*();
		~HasPtr();
	private:
		string *ps;
		int i;
		size_t *use;
};

HasPtr::~HasPtr()
{
	if(--*use == 0) {
		cout << "delete" << endl;
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*(rhs.use);
	if(--*use == 0) {
		cout << "delete" << endl;
		delete ps;
		delete use;
	}

	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr& HasPtr::operator=(const string& str) 
{
	*ps = str;
	return *this;
}

string & HasPtr::operator*()
{
	return *ps;
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
	HasPtr p1("Hi,Jack");//构造函数
	HasPtr p2 = p1;//拷贝构造
	p1 = "Hi,Aimi";//拷贝赋值运算

	cout << *p1 << endl;
	cout << *p2 << endl;
	return 0;
}
