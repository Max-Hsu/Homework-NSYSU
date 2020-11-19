#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	char ctext[80];
	string input;
	cout<<"Enter a string less than 80 characters long.\n";
	getline(cin,input);
	cout<<"Your string reversed is :";
	strcpy(ctext,input.c_str());
	char *start,*end;
	start=ctext;
	end=ctext+strlen(ctext);
	int Scount=0,Ecount=0;
	for(int i=0;i<int(strlen(ctext));i++){
		char *tempS=start+i;
		char *tempE=end-i-1;
		if(*tempE==' '){
			Ecount++;
		}
		if(*tempS==' '){
			Scount++;
		}
		cout<<*tempE;
		if(tempS==end || tempE==start){
			break;
		}
	}
	cout<<"\nAnd your number of words is :";
	if(Scount==Ecount){
		cout<<Scount+1<<"\n";
	}
	return 0;
}