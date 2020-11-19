#include <iostream>

using namespace std;

class money{
	public:
		money(int year,int month,int day,int cost);
		int Jprint();
		int Fprint(int year,int month,int day);
	private:
		int year;
		int month;
		int day;
		int cost;
};