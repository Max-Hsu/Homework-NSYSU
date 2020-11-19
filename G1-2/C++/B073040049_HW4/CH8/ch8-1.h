#include <iostream>

using namespace std;

class Money{
	public:
		Money();
		Money(double amount);
		Money(int theDollars,int theCents);
		Money(int theDollars);
		double getAmount() const;
		int getDollars() const;
		int getCents() const;
		const Money percent(int percent)const;
		friend const Money operator +(const Money& amount1,const Money& amount2);
		friend const Money operator -(const Money& amount1,const Money& amount2);
		friend bool operator ==(const Money& amount1,const Money& amount2);
		friend bool operator <(const Money& amount1,const Money& amount2);
		friend bool operator <=(const Money& amount1,const Money& amount2);
		friend bool operator >=(const Money& amount1,const Money& amount2);
		friend bool operator >(const Money& amount1,const Money& amount2);
		friend const Money operator -(const Money& amount1);//not to change its value but assign to another one
		friend ostream& operator <<(ostream& outputs,const Money& amount);
		friend istream& operator >>(istream& inputs,Money& amount);//because it needs to be change
	private:
		int dollars;
		int cents;
		
		int dollarsPart(double amount)const;
		int centsPart(double amount)const;
		int round(double number)const;
		
	
};
