#include <iostream>
#include "1.h"
using namespace std;
DATE::DATE(int year,int month,int day):
year(year),month(month),day(day)
{
}
bool DATE::compare(const DATE& testify){
	return(year==(testify.year)&&month==(testify.month)&&day==(testify.day));
}
void DATE::Output(){
	cout<<"Data output\n"<<year<<" "<<month<<" "<<day<<"\n";
}
int main(){
	int tyear;
	int tmonth;
	int tday;
	cout<<"data input\n";
	cin>>tyear>>tmonth>>tday;
	DATE date1(tyear,tmonth,tday);
	cout<<"data input\n";
	cin>>tyear>>tmonth>>tday;
	DATE date2(tyear,tmonth,tday);
	date1.Output();
	date2.Output();
	if(date1.compare(date2)){
		cout<<"Comparison Result : the Same\n";
	}
	else{
		cout<<"Comparison Result : different\n";

	}
	return 0;
}