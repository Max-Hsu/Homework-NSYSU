#include <iostream>
#include <string>
using namespace std;
void pr(string a,string b){
	cout<<"Result:"<<a<<" "<<b<<endl;
}
void pr(string a,string b,string c){
	cout<<"Result:"<<a<<" "<<b<<" "<<c<<endl;
}
int main(){
	int num;
	string a,b,c;
	cout<<"enter the number of input(neither 2 nor 3):";
	cin>>num;
	if(num==2){
		cin>>a>>b;
		pr(a,b);
	}
	else if(num==3){
		cin>>a>>b>>c;
		pr(a,b,c);
	}
	return 0;
	
}