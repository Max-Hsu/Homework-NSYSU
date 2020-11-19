#include <iostream>
#include <vector>
#include "ch7-8.h"
#include <algorithm>
using namespace std;

classOfScore::classOfScore(){}
void classOfScore::Input(){
	cout<<"Enter each grade and then -1 to stop.\n";
	int numInput;
	cin>>numInput;
	while(numInput!=-1){
		scores.push_back(numInput);
		cin>>numInput;
	}
}
void classOfScore::Output(){
	
	sort(scores.begin(),scores.begin()+scores.size());
	int counter=0;
	int maxNum=scores[scores.size()-1];
	vector<int>::iterator run;
	run=scores.begin();
	for(int i=0;i<=maxNum;i++){
		while((*run)==i){
			counter++;
			run++;
		}
		cout<<counter<<" grade(s) of "<<i<<"\n";
		counter=0;
	}
	
}
int main(){
	class classOfScore test;
	test.Input();
	test.Output();
	return 0;
}