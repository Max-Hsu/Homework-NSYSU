#include <iostream>
#include "ch8-4.h"
#include <stdlib.h>
using namespace std;

charpair::charpair(){
	for(int i=0;i<10;i++){
		set[i]=defaultchar;
	}
	sizeofset=10;
}
charpair::charpair(int size){
	sizeofset=size;
	if(sizeofset>100){
		cout<<"Wrong input\n";
		_Exit(1);
	}
	for(int i=0;i<sizeofset;i++){
		set[i]=defaultchar;
	}
}
charpair::charpair(int size,char symbol){
	sizeofset=size;
	if(sizeofset>100){
		cout<<"Wrong input\n";
		_Exit(1);
	}
	for(int i=0;i<sizeofset;i++){
		set[i]=symbol;
	}
}
char& charpair::operator [](int index){
	return set[index];
}
void charpair::outputsize(){
	cout<<"\nSize : "<<sizeofset;
}

int main(){
	charpair fortest;
	int testsz;
	char inputSymbol;
	cout<<"Default output(10):";
	for(int i=0;i<10;i++){
		cout<<fortest[i]<<" ";
	}
	fortest.outputsize();
	cout<<"\n-----clear array-----\n";
	cout<<"First sz member of the char array to # :";
	cin>>testsz;
	fortest=charpair(testsz);
	for(int i=0;i<testsz;i++){
		cout<<fortest[i]<<" ";
	}
	fortest.outputsize();
	cout<<"\n-----clear array-----\n";
	cout<<"First sz member of the char array to ? :";
	cin>>testsz>>inputSymbol;
	fortest=charpair(testsz,inputSymbol);
	for(int i=0;i<testsz;i++){
		cout<<fortest[i]<<" ";
	}
	fortest.outputsize();
	cout<<"\n";
	return 0;
}