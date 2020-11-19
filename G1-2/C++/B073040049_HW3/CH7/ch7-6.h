#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef PIZZA
class pizzaData{
	public:
		pizzaData(string size,string type,int pep,int che);
		void outputDescription();
		int computePrize();
	private:
		string size;
		string type;
		int pep;
		int che;
};
class Order{
	public:
		Order();
		Order(string size,string type,int pep,int che);
		void outputDescription();
		void computePrize();
		void order(string size,string type,int pep,int che);
	private:
		vector<class pizzaData> Data;

};
#define PIZZA
#endif