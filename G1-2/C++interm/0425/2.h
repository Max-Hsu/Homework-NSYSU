#include <iostream>
#include <string>
using namespace std;

class DATE{
	public:
		DATE(string name,int year,int month,int day);
		static int allstu;
		void Output();
	private:
		string name;
		int year;
		int month;
		int day;
		
};