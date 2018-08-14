#include <iostream>
#include <string>
#include <map>

using namespace std;

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
	map<string, int> map1;
	string word;
	cin >> word;

	map1.insert({word,1}); // map 不允许key值重复
	map1.insert(make_pair(word, 2));
	map1.insert(pair<string, int>(word, 3));
	map1.insert(map<string, int>::value_type(word, 4));

	for(auto &p : map1) {
		cout << "word: " << p.first << "\tnum:" << p.second << endl;
	}
	
	multimap<string, int> map2;
	map2.insert({word,1});
	map2.insert(map<string, int>::value_type(word, 4));
	for(auto &p : map2) {
		cout << "word: " << p.first << "\tnum:" << p.second << endl;
	}
	//cout << map2.erase(word) << endl; erase 返回删除元素的个数，对于multimap来说返回值有可能大于1

	return 0;
}
