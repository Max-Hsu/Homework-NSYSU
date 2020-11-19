#include <iostream>
#include <string>
using namespace std;

class BoxOfProduce{
	public:
	BoxOfProduce(string lista[]);
	void Change(int index,string name);
	void Output();
	private:
	string list[3];
};