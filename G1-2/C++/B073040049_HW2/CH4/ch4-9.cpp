#include <iostream>
#include <string>
const double ounceToGram = 28.349523;
const double GramToOunce = 0.0352739619;
using namespace std;
void input_p(float &pound,float &ounces){
	cout<<"Input pound : ";
	cin>>pound;
	cout<<"Input ounces : ";
	cin>>ounces;
}
void calc_p(float &pound,float &ounces ,int &kilogram ,float &gram){
	ounces+=pound*16;
	gram=ounces*ounceToGram;
	kilogram=gram/1000;
	gram-=kilogram*1000;
}
void output_p(int &kilogram ,float &gram){
	cout<<"Weight : "<<kilogram<<"kg and "<<gram<<" g "<<endl;
	
}
void input_g(float &kilogram,float &gram){
	cout<<"Input kilogram : ";
	cin>>kilogram;
	cout<<"Input gram : ";
	cin>>gram;
}
void calc_g(float &kilogram,float &gram ,int &pound ,float &ounces){
	gram+=kilogram*1000;
	ounces=gram*GramToOunce;
	pound=ounces/16;
	ounces-=pound*16;
}
void output_g(int &pound ,float &ounces){
	cout<<"Weight : "<<pound<<" pound and "<<ounces<<" ounces "<<endl;
	
}

int main(){
	int chooice;
	string choice="yes";
	while(choice=="yes"){
	cout<<"If you want conver pound and ounces to kg and g , enter 1"<<endl;
	cout<<"If you want conver kg and g to pound and ounces , enter 2"<<endl;
	cin>>chooice;
	if(chooice==1){
		float pound,ounces;
		int kilogram;
		float gram;
		input_p(pound,ounces);
		calc_p(pound,ounces,kilogram,gram);
		output_p(kilogram,gram);
	}
	else{
		float kilogram,gram;
		int pound;
		float ounces;
		input_g(kilogram,gram);
		calc_g(kilogram,gram,pound,ounces);
		output_g(pound,ounces);
	}

	cout<<"Keep calculating?? yes/no"<<endl;
	cin>>choice;
	}
	return 0;
}