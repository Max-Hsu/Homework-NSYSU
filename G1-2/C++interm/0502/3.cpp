#include <iostream>
#include <string>
using namespace std;
int yeararr[]={31,28,31,30,31,30,31,31,30,31,30,31};
class Date{
	public:
		Date(int iyear,int imonth,int iday);
		Date();
		friend bool operator<(class Date& Date1,class Date& Date2);
		friend bool operator>(class Date& Date1,class Date& Date2);
		friend bool operator==(class Date& Date1,class Date& Date2);
		friend Date& operator+(class Date& Date1,int numday);
		friend int operator-(class Date& Date1,class Date& Date2);

		void output();
		private:
		int year,month,day;
};
bool operator>(class Date& Date1,class Date& Date2){
	if(Date1.year>Date2.year){
		return true;
	}
	else if(Date1.year==Date2.year){
		if(Date1.month>Date2.month){
			return true;
		}
	}
	else if(Date1.year==Date2.year && Date1.month==Date2.month){
		if(Date1.day>Date2.day){
			return true;
		}
	}
	return false;
}
bool operator<(class Date& Date1,class Date& Date2){
	if(Date1.year<Date2.year){
		return true;
	}
	else if(Date1.year==Date2.year){
		if(Date1.month<Date2.month){
			return true;
		}
	}
	else if(Date1.year==Date2.year && Date1.month==Date2.month){
		if(Date1.day<Date2.day){
			return true;
		}
	}
	return false;
}
bool operator==(class Date& Date1,class Date& Date2){
	if(Date1.year==Date2.year && Date1.month==Date2.month && Date1.day==Date2.day){
		return true;
	}
	return false;
}
Date& operator+(class Date& Date1,int numday){
	Date1.day+=numday;
	if(Date1.month==1 && Date1.month==3 && Date1.month==5 && Date1.month==7 && Date1.month==8 && Date1.month==10 && Date1.month==12){
		Date1.month+=Date1.day/31;
		Date1.day%=31;
	}
	else if(Date1.month==2){
		Date1.month+=Date1.day/28;
		Date1.day%=28;
	}
	else{
		Date1.month+=Date1.day/30;
		Date1.day%=30;
	}
	if(Date1.month>12){
		Date1.year+=Date1.month/12;
		Date1.month%=12;
	}
	return Date1;
}
int operator-(class Date& Date1,class Date& Date2){
	int monday1=0;
	int monday2=0;
	for(int i=1;i<Date1.month;i++){
		monday1+=yeararr[i-1];
	}
	for(int i=1;i<Date2.month;i++){
		monday2+=yeararr[i-1];
	}
	monday1+=Date1.day;
	monday2+=Date2.day;
	return (Date1.year-Date2.year)*365+monday1-monday2;
}
Date::Date(int iyear,int imonth,int iday):
day(iday),month(imonth),year(iyear)
{}
Date::Date(){}
void Date::output(){
	cout<<year<<" / "<<month<<" / "<<day<<"\n";
}
int main(){
	int iyear,imonth,iday,numday;
	string choice1;
	cout<<"Please enter 2 dates to test:\n";
	cout<<"Enter the date1 : ";
	cin>>iyear>>imonth>>iday;
	Date Date1(iyear,imonth,iday);
	cout<<"Enter the date2 : ";
	cin>>iyear>>imonth>>iday;
	Date Date2(iyear,imonth,iday);
	
	cout<<"From";
	Date1.output();
	cout<<"to";
	Date2.output();
	cout<<Date1-Date2<<"days";
	return 0;
}