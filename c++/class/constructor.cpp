#include <iostream>

class Box {
	private:
		double length;
		double height;
		double width;
		double weight;

	public:
		//构造函数
		Box(double len, double hei, double wid, double wei)
			: length(len), height(hei), width(wid), weight(wei) {

			}

		Box(double len) {//重载 构造函数
			length = len;
		}
		
		Box (double len, double hei) :Box(12.3, 0, 10, 10) //委托构造函数
		{
			length = len;
			height = hei;
		}

		~Box() {

		}

		Box& getMember(){
			std::cout << length << " " << height << " " << width << " " << weight << " " << std::endl;
			return *this;
		}
};

int main(int argc, char *argv[])
{
	Box box(10.9, 5.6, 4.5, 10);
	box.getMember();


	Box box1(10.9);
	box1.getMember();

	Box box2(10.9, 9.9);
	box2.getMember();
	return 0;
}
