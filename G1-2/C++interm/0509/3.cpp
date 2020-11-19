#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	while(cin.peek()!='0' && cin.peek()!='-'){
		string in;
		char copy[100];
		cin>>in;
		if(in[0]=='0' || in[0] == '-'){
			break;
		}
		strcpy(copy,in.c_str());
		for(int i=in.size()-1;i>=0;i--){
			cout<<copy[i];
		}
		cout<<"\n";
	}
	return 0;
}