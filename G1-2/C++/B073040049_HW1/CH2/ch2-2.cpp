#include <iostream>
using namespace std;

int main(){
	int month=1;
	float money=0;
	int withdraw=0;
	float rate=0;
	cout<<"deposit:";
	cin>>money;
	cout<<"rate:";
	cin>>rate;
	cout<<"fixed amount withdraw every month:";
	cin>>withdraw;
	cout<<"months\tinterest\tprincipal"<<endl;
	float interest=0;
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	while(withdraw<money){
				money-=withdraw;
				interest=money*rate;
				money+=interest;
				cout<<month<<" \t "<<interest<<" \t\t "<<money<<endl;
				month++;
	}
	interest=money*rate;
	money+=interest;
	cout<<"number of payments = "<<month<<" last months interest = "<<interest<<" last payment = "<<money<<endl;
	
	
	
	
	
	return 0;
	}