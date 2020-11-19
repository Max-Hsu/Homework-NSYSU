#include <iostream>

using namespace std;
const int value[4]={10,20,30,40};
bool calc_fun(int &itemCode,int &voucher_value){
	return(value[itemCode-1]<=voucher_value);
}
int main(){
	int voucher_value;
	int choice;
	cout<<"1.Bagel : "<<value[0]<<endl;
	cout<<"2.Cake : "<<value[1]<<endl;
	cout<<"3.Croissant : "<<value[2]<<endl;
	cout<<"4.Toast : "<<value[3]<<endl;
	cout<<"Input your value of voucher : ";
	cin>>voucher_value;
	while(voucher_value>0)
	{
		cout<<"Which item you want? ";
		cin>>choice;
		if(calc_fun(choice,voucher_value)){
			cout<<"The price iof item which you buy : "<<value[choice-1]<<endl;
			voucher_value-=value[choice-1];
			cout<<"You still have value of voucher : "<<voucher_value<<endl;
		}
		else{
			cout<<"You can't buy this ,the thing you want to buy is higher price than your voucher is"<<endl;
		}
	}
	cout<<"You don't have enough value of voucher to buy anything"<<endl;
	return 0;
}