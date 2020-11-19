#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
	string name;
	fstream data;
	int temp=-1;
	while(true){
	cout<<"Enter a file name:\n";
	cin>>name;
	data.open(name,fstream::in);
	if(data.fail()){
		cout<<"No such a file\n";
		break;
		}
	fstream out;
	out.open(name+"_out",fstream::out);
	cout<<"build "<<name+"_out\n";
	while(!data.eof()){
		int num;
		data>>num;
		if((num-temp)==4){
			out<<num<<"\n";
			temp=num;
		}
		else{
			out.close();
			data.close();
			break;
		}
		}
	return 0;
	}
}