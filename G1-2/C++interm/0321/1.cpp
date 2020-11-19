#include <iostream>

using namespace std;
void passinreference(int &x,int &y){
	int temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"In swap reference function : "<<x<<" "<<y<<endl;
}
void passinvalue(int x,int y){
	int temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"In swap value function : "<<x<<" "<<y<<endl;
}
int main(){
	int x,y;
	cout<<"Enter two numbers:"<<endl;
	cin>>x>>y;
	cout<<"Your initial numbers: "<<x<<" "<<y<<endl;
	
	passinvalue(x,y);
	cout<<"In main function (after swap_value)"<<x<<" "<<y<<endl;
	passinreference(x,y);
	cout<<"In main function (after swap_value)"<<x<<" "<<y<<endl;
	
	return 0;
}