#include <iostream>
#include <string>

using namespace std;
#ifndef PIZZA
class pizza{
	public:
		pizza(string size,string type,int pep,int che);
		void outputDescription();
		void computePrize();
	private:
		string size;
		string type;
		int pep;
		int che;
};
#define PIZZA
#endif