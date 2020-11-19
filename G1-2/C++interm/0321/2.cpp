#include <iostream>
#include <string>
using namespace std;
void str_print(string str,int len=1){
	if(len==1){
		cout<<"output:"<<str<<"!"<<endl;
	}
	else if(len>5){
		cout<<"output:"<<str<<"~"<<endl;
	}
	else{
		cout<<"output:"<<str<<"*"<<endl;
	}
}
int main(){
	string aa;
	cout<<"input a string"<<endl;
	cin>>aa;
	str_print(aa);
	str_print(aa,aa.length());
}