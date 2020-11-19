#include <iostream>

using namespace std;

class DATE{
	public:
		DATE(int year,int month,int day);
		bool compare(const DATE& test);
		void Output();
	private:
		int year;
		int month;
		int day;
};