#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;
typedef vector<string>::size_type line_no;
vector<string> file;
map<string, set<line_no>> wm;  //map container

//思路：
//一个vector存储文本
//一个container存储文本关键字和行号
//寻找是搜寻association container中是否有匹配的关键字

string cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))//不是标点符号
			ret += tolower(*it);
	}

	return ret;
}

void input_text(ifstream &is)
{
	string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			/*auto flag =*/ wm[cleanup_str(word)].insert(n);//insert value to set container 
			/*if (!flag.second) {
				cerr << "the element is existed in container." << endl;
				continue;
			}*/
		}
	}
}

ostream &query_and_print(const string &sought, ostream &os)
{
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		os << sought << "未发现" << endl;
	} else {
		auto lines = loc->second;
		os << sought << "发现" << lines.size() << endl;
		for (auto num : lines) {
			os << "\t(第" << num + 1 << "行)"
				<< *(file.begin() + num) << endl;
		}
	}

	return os;
}

void runQueries(ifstream &infile) 
{
	input_text(infile);
	while (true) {
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") //q or eof exit loop
			break;

		query_and_print(s, cout) << endl;
	}
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
	ifstream infile;
	if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No input file." << endl;
		return -1;
	}

	runQueries(infile);

	return 0;
}
