#include <iostream>
#include <string>
const double ounceToGram = 28.349523;
using namespace std;
void input(float &pound,float &ounces){
	cout<<"Input pound : ";
	cin>>pound;
	cout<<"Input ounces : ";
	cin>>ounces;
}
void calc(float &pound,float &ounces ,int &kilogram ,float &gram){
	ounces+=pound*16;
	gram=ounces*ounceToGram;
	kilogram=gram/1000;
	gram-=kilogram*1000;
}
void output(int &kilogram ,float &gram){
	cout<<"Weight : "<<kilogram<<"kg and "<<gram<<" g "<<endl;
	
}
int main(){
	float pound,ounces;
	int kilogram;
	float gram;
	string choice="yes";
	while(choice=="yes"){
	input(pound,ounces);
	calc(pound,ounces,kilogram,gram);
	output(kilogram,gram);
	cout<<"Keep calculating?? yes/no"<<endl;
	cin>>choice;
	}
	return 0;
}