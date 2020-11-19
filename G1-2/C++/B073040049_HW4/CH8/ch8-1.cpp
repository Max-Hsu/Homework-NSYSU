#include <iostream>
#include "ch8-1.h"
using namespace std;



Money::Money(){}
Money::Money(double amount){
	cents=(amount-(int)amount)*100;
	dollars=amount/1;
}
Money::Money(int theDollars,int theCents){
	cents=theCents;
	dollars=theDollars;
}
Money::Money(int theDollars){
	cents=0;
	dollars=theDollars;
}
double Money::getAmount()const{
	return (dollars+cents*0.01);
}
int Money::getCents()const{
	return cents;
}
int Money::getDollars()const{
	return dollars;
}
const Money Money::percent(int percent)const{
	return Money((dollars+cents*0.01)*(double)percent*((double)0.01));
}
const Money operator + (const Money& amount1,const Money& amount2){
	return Money(amount1.dollars+amount2.dollars,amount1.cents+amount2.cents);
}
const Money operator - (const Money& amount1,const Money& amount2){
	return Money(amount1.dollars-amount2.dollars,amount1.cents-amount2.cents);
}
bool operator == (const Money& amount1,const Money& amount2){
	return ((amount1.dollars==amount2.dollars)&&(amount1.cents==amount2.cents));
}
bool operator <= (const Money& amount1,const Money& amount2){
	return ((amount1.dollars<=amount2.dollars)&&(amount1.cents<=amount2.cents));
}
bool operator < (const Money& amount1,const Money& amount2){
	return ((amount1.dollars<amount2.dollars)&&(amount1.cents<amount2.cents));
}
bool operator >= (const Money& amount1,const Money& amount2){
	return ((amount1.dollars>=amount2.dollars)&&(amount1.cents>=amount2.cents));
}
bool operator > (const Money& amount1,const Money& amount2){
	return ((amount1.dollars>amount2.dollars)&&(amount1.cents>amount2.cents));
}
ostream& operator << (ostream& outputs,const Money& amount){
	outputs<<"$"<<amount.dollars+((double)amount.cents/100);
	return outputs;
}
istream& operator >> (istream& inputs,Money& amount){
	int tDollars;
	int tCents;
	inputs>>tDollars>>tCents;
	amount.dollars=tDollars;
	amount.cents=tCents;
	return inputs;
}
int main(){
	double getmoney;
	int getpercent;
	cout<<"Enter an amount of money : $";
	cin>>getmoney;
	cout<<"Enter a percent you wish to take of your amount : ";
	cin>>getpercent;
	Money your(getmoney);
	Money my(10,9);
	cout<<"Your amount is"<<your<<"\n";
	cout<<"My amount is"<<my<<"\n";
	cout<<getpercent<<"% of your amount is "<<your.percent(getpercent)<<"\n";
	cout<<"15% of my amount is "<<my.percent(15)<<"\n";
	cout<<"One of us is richer.\n";
	
	cout<<your<<" + "<<my;
	Money combine=your+my;
	if((your+my)==combine){
		cout<<" equals ";
	}
	else{
		cout<<" not equals ";
	}
	cout<<your+my<<"\n";
	
	cout<<your<<" - "<<my;
	Money minus=your-my;
	if((your-my)==minus){
		cout<<" equals ";
	}
	else{
		cout<<" not equals ";
	}
	cout<<your-my<<"\n";
	
	
	cout<<"Your amount";
	if(your>=my){
		cout<<" is ";
	}
	else{
		cout<<" is not ";
	}
	cout<<"greater than or equal to my amount\n";
	
	cout<<"The sum of our amounts";
	if(combine>minus){
		cout<<" is ";
	}
	else{
		cout<<" is not ";
	}
	cout<<"greater than the difference\n";
	
	cout<<"Your amount";
	if(your>my){
		cout<<" is ";
	}
	else{
		cout<<" is not ";
	}
	cout<<"greater than my amount\n";
	
	cout<<"The sum of our amounts";
	if(combine>=minus){
		cout<<" is ";
	}
	else{
		cout<<" is not ";
	}
	cout<<"greater than or equal to the difference\n";
	return 0;
}