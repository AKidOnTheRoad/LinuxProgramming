#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//int read(vector<int> * &pvec) #comment1
int read(shared_ptr<vector<int>> &pvec)
{
	int val;
	while (cin >> val) {
		(*pvec).push_back(val);
	}

	return 0;
}

//int write(const vector<int> *pvec) #comment1
int write(shared_ptr<vector<int>> pvec)
{
	for(auto p : *pvec) {
		cout << p << endl;
	}

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
	//vector<int> *pvec = new vector<int>();#comment1:use new 
	shared_ptr<vector<int>> pvec = make_shared<vector<int>>();
	read(pvec);
	write(pvec);
	//delete pvec;#comment1
	//pvec = NULL;#comment1
	return 0;
}
