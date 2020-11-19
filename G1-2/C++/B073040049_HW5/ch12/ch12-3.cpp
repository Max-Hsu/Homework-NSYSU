#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string name;
	fstream data;
	int counter=0;
	bool needOne;
	while(true){
	cout<<"Enter a file name:\n";
	cin>>name;
	data.open(name,fstream::in);
	if(data.fail()){
		cout<<"No such a file\n";
		break;
		}
	while(!data.eof()){
		string get;
		data>>get;
		if(get==""){
			counter-=1;
		}
		counter++;
	}
	if((counter%2)==0){
		needOne=false;
	}
	else{
		needOne=true;
	}
	data.seekg(0,data.beg);
	if(needOne){
		int num1;
		string junk;
		for(int i=0;i<counter/2;i++){
			getline(data,junk);
		}
		data>>num1;
		cout<<"Median number : "<< counter/2+1 <<" , value "<<num1<<"\n";
	}
	else{
		int num1;
		int num2;
		string junk;
		for(int i=0;i<counter/2-1;i++){
			getline(data,junk);
		}
		data>>num1;
		data>>num2;
		cout<<"Median number : "<< counter/2 <<" and "<<counter/2+1 <<" , value "<<(num1+num2)/2<<"\n";
	}
	if((counter%4)==0){
		needOne=false;
	}
	else{
		needOne=true;
	}
	data.seekg(0,data.beg);
	cout<<"quartile : ";
	if(needOne){
		int num1;
		string junk;
		for(int i=0;i<counter/4;i++){
			getline(data,junk);
		}
		data>>num1;
		cout<<num1<<" ";
		for(int i=counter/4;i<counter/2;i++){
			getline(data,junk);
		}
		data>>num1;
		cout<<num1<<" ";
		for(int i=counter/2;i<counter*3/4;i++){
			getline(data,junk);
		}
		data>>num1;
		cout<<num1<<"\n";
	}
	else{
		int num1;
		int num2;
		string junk;
		for(int i=0;i<counter/4;i++){
			getline(data,junk);
		}
		data>>num1;
		data>>num2;
		cout<<(num1+num2)/2<<" ";
		for(int i=counter/4+1;i<counter/2;i++){
			getline(data,junk);
		}
		data>>num1;
		data>>num2;
		cout<<(num1+num2)/2<<" ";
		for(int i=counter/2+1;i<counter/4*3;i++){
			getline(data,junk);
		}
		data>>num1;
		data>>num2;
		cout<<(num1+num2)/2<<"\n";
	}
	}
	
	
	return 0;
}