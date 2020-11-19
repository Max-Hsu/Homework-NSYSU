#include <iostream>
#include <string>
using namespace std;

int main(){
	int num;
	if(cin.peek()=='U'){
		cin.get();
		if(cin.peek()=='S'){
			cin.ignore(2,'D');
			cin>>num;
			cout<<"TWD"<<num*30;
		}
	}
	else if(cin.peek()=='T'){
		cin.get();
		if(cin.peek()=='W'){
			cin.ignore(2,'D');
			cin>>num;
			cout<<"USD"<<num/30;
		}
	}
	else{
		cout<<"No\n";
	}
	return 0;
}