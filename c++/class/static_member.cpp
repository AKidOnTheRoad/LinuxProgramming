#include <iostream>

class Box{
	private:
		double length;
		double width;
	public:
		static int count;
		Box(double len, double wid)
		{
			length = len;
			width = wid;
			count++;
		}
		double area()
		{
			std::cout << count << std::endl;
			return length*width;
		}
		static int getCount()
		{
			return count;
		}
};

int Box::count = 0;

int main(int argc, char *argv[]) 
{
	Box box(3.5, 5.3);
	std::cout << "area=" << box.area() << std::endl;

	std::cout << box.count << std::endl;
	std::cout << Box::count << std::endl;
	std::cout << box.getCount() << std::endl;
	return 0;

}
