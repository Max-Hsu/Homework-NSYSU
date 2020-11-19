#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string name;
	int H_temp=0;
	int H_month=0;
	int counter=1;
	cout<<"Please enter the file name to read temperature from : ";
	cin>>name;
	name+=".txt";
	fstream filea;
	filea.open(name,fstream::in);
	while(!filea.eof()){
		int T_temp;
		filea>>T_temp;
		if(T_temp > H_temp){
			H_temp = T_temp;
			H_month = counter;
		}
		counter++;
	}
	cout<<"The hottest month : "<<H_month<<"\n";
	cout<<"The temperature is : "<<H_temp<<"\n";
	return 0;
}