#include <iostream>
#include <string>
using namespace std;
class Date{
	public:
		Date(int iyear,int imonth,int iday);
		friend bool operator<(class Date& Date1,class Date& Date2);
		friend bool operator>(class Date& Date1,class Date& Date2);
		friend bool operator==(class Date& Date1,class Date& Date2);
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
Date::Date(int iyear,int imonth,int iday):
day(iday),month(imonth),year(iyear)
{}
void Date::output(){
	cout<<year<<" / "<<month<<" / "<<day<<"\n";
}
int main(){
	int iyear,imonth,iday;
	string choice1,choice2;
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
	cout<<"Choose two dates to compare ( > , < , = ) : ";
	cin>>choice1>>choice2;
	int idn1=int(choice1[choice1.size()-1])-48;
	int idn2=int(choice2[choice2.size()-1])-48;
	if(idn1==1 && idn2==1){
		Date1.output();
		if(Date1 > Date1){
			cout<<" > ";
		}
		else if(Date1 == Date1){
			cout<<" == ";
		}
		else if(Date1 < Date1){
			cout<<" < ";
		}
		Date1.output();
	}
	else if(idn1==1 && idn2==2){
		Date1.output();
		if(Date1 > Date2){
			cout<<" > ";
		}
		else if(Date1 == Date2){
			cout<<" == ";
		}
		else if(Date1 < Date2){
			cout<<" < ";
		}
		Date2.output();
	}
	else if(idn1==1 && idn2==3){
		Date1.output();
		if(Date1 > Date3){
			cout<<" > ";
		}
		else if(Date1 == Date3){
			cout<<" == ";
		}
		else if(Date1 < Date3){
			cout<<" < ";
		}
		Date3.output();
	}
	else if(idn1==2 && idn2==1){
		Date2.output();
		if(Date2 > Date1){
			cout<<" > ";
		}
		else if(Date2 == Date1){
			cout<<" == ";
		}
		else if(Date2 < Date1){
			cout<<" < ";
		}
		Date1.output();
	}
	else if(idn1==2 && idn2==2){
		Date2.output();
		if(Date2 > Date2){
			cout<<" > ";
		}
		else if(Date2 == Date2){
			cout<<" == ";
		}
		else if(Date2 < Date2){
			cout<<" < ";
		}
		Date2.output();
	}
	else if(idn1==2 && idn2==3){
		Date2.output();
		if(Date2 > Date3){
			cout<<" > ";
		}
		else if(Date2 == Date3){
			cout<<" == ";
		}
		else if(Date2 < Date3){
			cout<<" < ";
		}
		Date3.output();
	}
	else if(idn1==3 && idn2==1){
		Date3.output();
		if(Date3 > Date1){
			cout<<" > ";
		}
		else if(Date3 == Date1){
			cout<<" == ";
		}
		else if(Date3 < Date1){
			cout<<" < ";
		}
		Date1.output();
	}
	else if(idn1==3 && idn2==2){
		Date3.output();
		if(Date3 > Date2){
			cout<<" > ";
		}
		else if(Date3 == Date2){
			cout<<" == ";
		}
		else if(Date3 < Date2){
			cout<<" < ";
		}
		Date2.output();
	}
	else if(idn1==3 && idn2==3){
		Date3.output();
		if(Date3 > Date3){
			cout<<" > ";
		}
		else if(Date3 == Date3){
			cout<<" == ";
		}
		else if(Date3 < Date3){
			cout<<" < ";
		}
		Date3.output();
	}
	return 0;
}