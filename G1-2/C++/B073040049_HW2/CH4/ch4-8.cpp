#include <iostream>
#include <string>
const double GramToOunce = 0.0352739619;
using namespace std;
void input(float &kilogram,float &gram){
	cout<<"Input kilogram : ";
	cin>>kilogram;
	cout<<"Input gram : ";
	cin>>gram;
}
void calc(float &kilogram,float &gram ,int &pound ,float &ounces){
	gram+=kilogram*1000;
	ounces=gram*GramToOunce;
	pound=ounces/16;
	ounces-=pound*16;
}
void output(int &pound ,float &ounces){
	cout<<"Weight : "<<pound<<" pound and "<<ounces<<" ounces "<<endl;
	
}
int main(){
	float kilogram,gram;
	int pound;
	float ounces;
	string choice="yes";
	while(choice=="yes"){
	input(kilogram,gram);
	calc(kilogram,gram,pound,ounces);
	output(pound,ounces);
	cout<<"Keep calculating?? yes/no"<<endl;
	cin>>choice;
	}
	return 0;
}