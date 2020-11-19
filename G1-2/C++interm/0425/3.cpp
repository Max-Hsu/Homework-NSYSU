#include <iostream>
#include "3.h"
#include <vector>
using namespace std;
money::money(int year,int month,int day,int cost):
year(year),month(month),day(day),cost(cost)
{
}
int money::Jprint(){
	cout<<year<<"-"<<month<<"-"<<day<<" "<<cost<<"\n";
	return cost;
}
int money::Fprint(int fyear,int fmonth,int fday){
	if((fyear==year)&&(fmonth==month)&&(fday==day)){
		cout<<year<<"-"<<month<<"-"<<day<<" "<<cost<<"\n";
		return cost;
	}
	return 0;
}
int main(){
	int choice;
	cout<<"1.add data\n2.print\n3.search\n4.exit\n";
	cin>>choice;
	vector<class money> all;
	while(choice<=3 && choice>=1){
		if(choice==1){
			int tyear,tmonth,tday,tcost;
			cin>>tyear>>tmonth>>tday>>tcost;
			all.push_back(money(tyear,tmonth,tday,tcost));
		}
		else if(choice==2){
			int sum=0;
			for(vector<class money>::iterator run=all.begin();run<all.end();run++){
				sum+=(*run).Jprint();
			}
			cout<<"sum : "<<sum<<"\n";
		}
		else if(choice==3){
			int fyear,fmonth,fday;
			int sum=0;
			cin>>fyear>>fmonth>>fday;
			for(vector<class money>::iterator run=all.begin();run<all.end();run++){
				sum+=(*run).Fprint(fyear,fmonth,fday);
			}
			cout<<"sum : "<<sum<<"\n";
	
		}
		
		cout<<"1.add data\n2.print\n3.search\n4.exit\n";
		cin>>choice;
	}
	
	return 0;
}