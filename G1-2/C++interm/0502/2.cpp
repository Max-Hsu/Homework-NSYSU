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
	while(yeararr[Date1.month-1]<Date1.day){
		Date1.day-=yeararr[Date1.month-1];
		Date1.month++;
		if(Date1.month>12){
			Date1.month=1;
			Date1.year++;
		}
	}
	return Date1;
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
	cout<<"Please enter 3 dates to test:\n";
	cout<<"Enter the date1 : ";
	cin>>iyear>>imonth>>iday;
	Date Date1(iyear,imonth,iday);
	cout<<"Enter the date2 : ";
	cin>>iyear>>imonth>>iday;
	Date Date2(iyear,imonth,iday);
	cout<<"Enter the date3 : ";
	cin>>iyear>>imonth>>iday;
	Date Date3(iyear,imonth,iday);
	cout<<"Date1 : ";
	Date1.output();
	cout<<"Date2 : ";
	Date2.output();
	cout<<"Date3 : ";
	Date3.output();
	cout<<"Choose a date to add (+) : ";
	cin>>choice1;
	cout<<"\n + ";
	cin>>numday;
	int idn1=int(choice1[choice1.size()-1])-48;
	Date Ndate;
	if(idn1==1){
		Ndate=Date1+numday;
	}
	else if(idn1==2){
		Ndate=Date2+numday;
	}
	else if(idn1==3){
		Ndate=Date3+numday;
	}
	Ndate.output();
	return 0;
}