#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "ch8-9.h"
using namespace std;
int iter=0;
BoxOfProduce::BoxOfProduce(string lista[]){
	for(int i=0;i<(rand()%iter)+1;i++){
		list.push_back(lista[rand()%iter]);
	}
}
BoxOfProduce::BoxOfProduce(vector<string> inputs):
list(inputs)
{}
void BoxOfProduce::Change(int index,string name){
	list[index-1]=name;
}
void BoxOfProduce::Output(){
	for(int i=0;i<int(list.size());i++){
		cout<<"("<<i+1<<")"<<list[i]<<"\t\t";
	}
	cout<<"\n";
}
const BoxOfProduce BoxOfProduce::operator +(const BoxOfProduce& addBox){
	vector<string> combiner;
	vector<string>::iterator runOdd;
	runOdd=combiner.end();
	combiner.insert(runOdd,list.begin(),list.end());
	runOdd=combiner.end();
	combiner.insert(runOdd,addBox.list.begin(),addBox.list.end());
	
	return combiner;
}
int main(){
	srand(time(NULL));
	string fruit[10];
	fstream file;
	file.open("produce.txt",fstream::in);
	
	while(!file.eof()){
		file>>fruit[iter];
		iter++;
	}
	BoxOfProduce Box1(fruit);
	cout<<"The box1 contains:\n";
	Box1.Output();
	cout<<"\n";
	
	BoxOfProduce Box2(fruit);
	cout<<"The box2 contains:\n";
	Box2.Output();
	cout<<"\n";
	
	
	BoxOfProduce Box3=Box1+Box2;
	cout<<"The box1+box2 contains:\n";
	Box3.Output();
	return 0;
}