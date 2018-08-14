#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class showE {
	public:
		showE(){
			num = 0;
		}
		void operator()(const std::string &s1){
			++num;
			std::cout << s1 << "\t";
		}
		void printNum(){
			std::cout << "num: " << num << std::endl;
		}
	private:
		int num;
};

bool isLarger(const std::string&s1, const std::string&s2)
{
	return s1.size() > s2.size();
}
void outPut(std::vector<std::string>&vec)
{
	for (auto p : vec)
		std::cout << p << " ";
	std::cout << std::endl;
}

void showEle(std::string &str)
{
	std::cout << str << " ";
}

int elimDups(std::vector<std::string> &vec)
{
	outPut(vec);

	sort(vec.begin(), vec.end(), isLarger);//排序

	auto end_unique = unique(vec.begin(), vec.end());//返回最后一个不唯一的元素的下一位置

	vec.erase(end_unique, vec.end());//删除两个迭代器之间的元素  左闭右开

	outPut(vec);

	for_each(vec.begin(), vec.end(), showEle);//for_each 遍历算法
	std::cout << std::endl;

	showE myshow = for_each(vec.begin(), vec.end(), showE());//for_each函数最后使用的参数为函数对象或者回调函数
	//myshow 初始化
	myshow.printNum();

    myshow = for_each(vec.begin(), vec.end(), showE());
	//myshow 赋值
	myshow.printNum();

	return 0;
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
	std::vector<std::string> vec;
	std::string str;
	while(std::cin >> str) {
		vec.push_back(str);
	}

	elimDups(vec);

	return 0;
}
