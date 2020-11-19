#include <iostream>
#include "2.h"
#include <string>
#include <vector>
using namespace std;
DATE::DATE(string name,int year,int month,int day):
name(name),year(year),month(month),day(day)
{
}

void DATE::Output(){
	cout<<"Data output\n"<<name<<" "<<year<<" "<<month<<" "<<day<<"\n";
}
int DATE::allstu = 0;
int main(){
	int tyear;
	int tmonth;
	int tday;
	string tname;
	vector<class DATE> all;
	cout<<"data input\n";
	cin>>tname;
	
	
	while(tname!="exit"){
	cin>>tyear>>tmonth>>tday;
	all.push_back(DATE(tname,tyear,tmonth,tday));
	cout<<"data input\n";
	cin>>tname;
	}

	for(vector<class DATE>::iterator run=all.begin();run<all.end();run++){
		(*run).Output();
	}
	DATE::allstu = int(all.size());
	cout<<"total students : "<<DATE::allstu<<"\n";
	return 0;
}