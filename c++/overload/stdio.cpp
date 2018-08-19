
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Box {
	friend istream& operator>> (istream &in, Box &box);
	friend ostream& operator<<(ostream &out, const Box &box);
	friend Box operator+(const Box& box1, const Box& box2);
	friend bool operator==(const Box& box1, const Box& box2);
	//friend bool operator!=(const Box& box1, const Box& box2);
	private:
		string No;
		int length;
		int height;
	public:
		Box& operator+=(const Box& box1);
		Box& operator++();
		Box& operator++(int);

		Box(string str = "NULL", int len = 1, int hei = 1)
		{
			this->No = str;
			this->length = len;
			this->height = hei;
		}

		~Box() {}
};

istream& operator>>(istream &in, Box &box)//友元函数  重载>>
{
	in >> box.No >> box.length >> box.height;
	if (!in) {
		box = Box();
	}

	return in;

}

ostream& operator<<(ostream &out, const Box &box)//友元函数 重载<<
{
	out << box.No << " " << box.length << " " << box.height;

	return out;
}

Box operator+(const Box& box1, const Box& box2)//非成员函数 重载+运算符
{
	Box sam;
	sam.No = box1.No + box2.No;
	sam.length = box1.length + box2.length;
	sam.height = box1.height + box2.height;

	return sam;
}

bool operator==(const Box& box1, const Box& box2)
{
	cout << "operator ==" << endl;
	cout << box1 << endl;
	cout << box2 << endl;
	return (box1.No == box2.No)&&(box1.length == box2.length)&&(box1.height  == box2.height);
}

/*
bool operator!=(const Box& box1, const Box& box2)
{

}*/

Box& Box::operator+=(const Box& box1)//成员函数 重载+= 赋值运算符
{
	
	No += box1.No;
	length += box1.length;
	height += box1.height;

	return *this;
}

Box& Box::operator++()//成员函数 重载前置++
{
	this->No += "12";
	cout << *this << endl;
	return *this;
}

Box& Box::operator++(int a)//成员函数 重载后置++
{
	this->No += "34";
	cout << *this << endl;
	return *this;
}
/************************************************************************
  Author          :xiaofei
  Mail            :jy_fengxiaofei@163.com
  Created Time    :2018-08-18 13:40:53 weeks:33
  Function Name   : main
  Description     :
  Input(s)        : argc            - The numbers of input value.
                  : **argv          - The input specific parameters.
  Output(s)       : NULL
  Returns         : 0
************************************************************************/
int main(int argc, char *argv[])
{
	Box box;
	cin >> box;
	cout << box;
	cout << endl;
	Box bb = box + box;
	cout << bb << endl;

	box += box;

	cout << box << endl;

//	cout << "box++ " << box++ << endl;//后置++ 运算
//	cout << "++box " << ++box << endl;//前置++ 运算

	cout << (box++ == ++box);//从右至左压栈
	return 0;
}
