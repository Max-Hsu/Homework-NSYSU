#include <iostream>
#include "ch8-8.h"
ostream& operator << (ostream& output,const Temperature& wantToOutput){
	output<<"In Kelvin : "<<wantToOutput.tempInK;
	output<<"\nIn Celisus : "<<convertToCe(wantToOutput.tempInK);
	output<<"\nIn Fahrenheit : "<<convertToFa(wantToOutput.tempInK);
	output<<"\n\n";
	return output;
}
istream& operator >> (istream& input,Temperature& wantToInput){
	double tempF;
	input>>tempF;
	wantToInput.tempInK=FToK(tempF);
	return input;
}
const bool Temperature::operator == (const Temperature& toTestify)const{
	return(tempInK==toTestify.tempInK);
}
double convertToCe(double tempInK){
	return tempInK-273.15;
}
double convertToFa(double tempInK){
	return tempInK*9/5-459.67;
}
double FToK(double Fa){
	return (Fa+459.67)*5/9;
}
using namespace std;

int main(){
	Temperature Temperature1;
	Temperature Temperature2;
	cout<<"Input a temperature1 in Fahrenheit.\n";
	cin>>Temperature1;
	cout<<Temperature1;
	
	cout<<"Input a temperature2 in Fahrenheit.\n";
	cin>>Temperature2;
	cout<<Temperature2;
	
	cout<<"Temperature1 == Temperature2 : ";
	if(Temperature1==Temperature2){
		cout<<"True\n";
	}
	else{
		cout<<"False\n";
	}
	return 0;
}