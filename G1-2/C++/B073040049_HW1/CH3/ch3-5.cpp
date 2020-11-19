#include <iostream>
using namespace std;
void calculation(){
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	float height,weight,age;
	cout<<"Give me your height in inches , weight in pounds , and age in years and I will give yiu your hat size , jacket size(inches at chest) and your waist size in inches."<<endl;
	cin>>height>>weight>>age;
	cout<<"hat size = "<< weight/height*2.9<<endl;
	int addjacket=age/10-2;
	cout<<"jacket size = "<<height*weight/288+(float)(1/8)*addjacket<<endl;
	int addwaist=age/2-13;
	cout<<"waist size = "<<weight/5.7+(float)(1/10)*addwaist<<endl;
}
int main(){
	char option;
	do{
		calculation();
		cout<<"enter Y or y to repeat the calculation , any other character ends.";
		cin>>option;
	}while(option=='Y'||option=='y');
	return 0;
}