#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BoxOfProduce{
	public:
	BoxOfProduce(string lista[]);
	BoxOfProduce(vector<string> inputs);
	void Change(int index,string name);
	void Output();
	const BoxOfProduce operator + (const BoxOfProduce& addBox);
	private:
	vector<string> list;
};