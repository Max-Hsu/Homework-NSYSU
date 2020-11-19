#include <iostream>

using namespace std;
class Date{
	public:
		friend istream& operator>>(istream & wantInput,Date & toInput);
		friend ostream& operator<<(ostream & wantOutput,const Date & toOutput);
	private:
		int year,month,day;
};
istream& operator>>(istream & wantInput,Date & toInput){
	cout<<"Year\n";
	wantInput>>toInput.year;
	cout<<"Month\n";
	wantInput>>toInput.month;
	cout<<"day\n";
	wantInput>>toInput.day;
}
ostream& operator<<(ostream & wantOutput,const Date & toOutput){
	wantOutput<<"Date:\n"<<toOutput.year<<" / "<<toOutput.month<<" / "<<toOutput.day;
}
int main(){
	Date day1;
	cin>>day1;
	cout<<day1;
	return 0;
}