#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
	families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, 
		const string &family, const string &child, const string &birthday)
{
	families[family].push_back({child, birthday});
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
	map<string, vector<pair<string, string>>> families;

	add_family(families, "zhang");
	add_child(families, "zhang", "Mike", "1994-10-10");
	add_child(families, "zhang", "Sherry", "1992-12-10");
	add_child(families, "lu", "Mike", "1994-10-10");
	add_family(families, "lu");


	map<string, vector<pair<string, string>>>::iterator beg;

	for (beg = families.begin(); beg != families.end(); beg++) {
		cout << beg->first;
		for ( vector<pair<string, string>>::iterator beg1 = beg->second.begin(); beg1 != beg->second.end(); beg1++) {
			cout << " " << beg1->first << " birthday: "<< beg1->second << endl;
		}
	}
	/*
	for (auto &m : families) {
		cout << m.first;
		for (auto &n : m.second) {
			cout << " " << n.first << " birthday: "<< n.second << endl;
		}
	}
*/
	return 0;
}
