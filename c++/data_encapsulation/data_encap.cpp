#include <iostream>

class Adder {
	public:
		Adder (int i = 0)
		{
			total = i;
		}
		void addNum(int Num)
		{
			total += Num;
		}
		int getTotal()
		{
			return total;
		}
	private:
		int total;
};

int main()
{
	Adder a;
	
	a.addNum(10);
	a.addNum(50);


	std::cout<< a.getTotal() << "\n";
	//std::cout<<a.total<<std::endl;
	return 0;

}
