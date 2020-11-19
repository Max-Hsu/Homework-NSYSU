#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "ch6-12.h"
using namespace std;
BoxOfProduce::BoxOfProduce(string lista[]){
	for(int i=0;i<3;i++){
		list[i]=lista[rand()%5];
	}
}
void BoxOfProduce::Change(int index,string name){
	list[index-1]=name;
}
void BoxOfProduce::Output(){
	for(int i=0;i<3;i++){
		cout<<"("<<i+1<<")"<<list[i]<<"\t\t";
	}
	cout<<"\n";
}
int main(){
	srand(time(NULL));
	string fruit[10];
	char choice=' ';
	fstream file;
	file.open("produce.txt",fstream::in);
	int iter=0;
	while(!file.eof()){
		file>>fruit[iter];
		iter++;
	}
	class BoxOfProduce Box(fruit);
	while(choice!='q'){
		if(choice=='c'){
			int num;
			string sub;
			cout<<"Enter index of item to change.\n";
			cin>>num;
			cout<<"Enter item to substitute.\n";
			cin>>sub;
			Box.Change(num,sub);
		}
		cout<<"The box contains : ";
		Box.Output();
		cout<<"Enter 'c' to change a bundle.\nEnter 'q' to quit.\n";
		cin>>choice;
	}
	cout<<"Final Contents :\n";
	Box.Output();
	cout<<"\n";
	return 0;
}