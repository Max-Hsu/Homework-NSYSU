#include <iostream>
#include <string>
#include <vector>
#include "ch10-8.h"

using namespace std;

int main(){
	int num;
	class tv defaulta;
	defaulta.set();
	defaulta.output();
	cout<<"Enter TV numbers\n";
	cin>>num;
	vector <class tv> list;
	for(int i=0;i<num;i++){
		list.push_back(tv(defaulta,i));
	}
	int choice;
	cout<<"Enter index of TV required of customization (input -1 to end)\n";
	cin>>choice;
	while(choice!=-1){
		list[choice].set();
		cout<<"Enter index of TV required of customization (input -1 to end)\n";
		cin>>choice;
	}
	for(int i=0;i<num;i++){
		list[i].output();
	}
	return 0;
}