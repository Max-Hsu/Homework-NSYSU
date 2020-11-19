#include <iostream>

using namespace std;

class Temperature{
	public:
		friend ostream& operator << (ostream& output,const Temperature& wantToOutput);
		friend istream& operator >> (istream& input,Temperature& wantToInput);
		const bool operator == (const Temperature& toTestify)const;
	private:
		double tempInK;

};
double convertToCe(double tempInK);
double convertToFa(double tempInK);
double FToK(double Fa);