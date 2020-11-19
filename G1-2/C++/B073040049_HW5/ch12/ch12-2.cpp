#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string name;
	fstream data;
	while(true){
	cout<<"Enter a file name:\n";
	cin>>name;
	data.open(name,fstream::in);
	if(data.fail()){
		cout<<"No such a file\n";
		break;
		}
	int counter=0;
	double adder=0;
	while(!data.eof()){
		string get;
		data>>get;
		if(get==""){
			counter-=1;
		}
		adder+=atof(get.c_str());
		counter++;
		}
	cout<<"Average of "<<counter<<" numbers is "<<adder/counter<<"\n";
	}
	
	
	return 0;
}