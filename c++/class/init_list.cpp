#include <iostream>
#include <string>

class A;//在使用这个类时，需要声明
class B {
	public:
	void clear(A&);
};

class A {
	void friend B::clear(A&);//classA声明友元成员函数时，该成员函数必须先要声明
};



class Screen {
	private:
		unsigned cursor = 0;
		unsigned height = 0, width = 0;
		std::string contents;

	public:
		typedef std::string::size_type pos;
		Screen() = default;
		Screen(unsigned ht, unsigned wd, char c): height(ht), width(wd), contents(wd*ht, c)//contents(wd*ht, c) -->string类型初始化方式
		{
		}
		Screen &move(unsigned r, unsigned c);
		Screen &set(char ch);
		Screen &set(unsigned r, unsigned c, char ch);
		Screen &display();
};

Screen & Screen::move(unsigned r, unsigned c)
{
	cursor = r * width + c;
	return *this;
}

Screen & Screen::set(char ch) 
{
	contents[cursor] = ch;
	return *this;
}

Screen & Screen::set(unsigned r, unsigned c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}

Screen & Screen::display()
{
	std::cout << contents;
	return *this;
}

int main(int argc, char *argv[])
{
	Screen sr(5, 5, 'C');
	sr.move(4, 0).set('#').display();

	std::cout << "\n";
	sr.display();
	std::cout << "\n";

	return 0;
}
