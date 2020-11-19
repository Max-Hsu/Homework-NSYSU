#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> grade;
	cout<<"Enter each grade and then -1 to stop\n";
	int inputa;
	cin>>inputa;
	while(inputa!=-1){
		grade.push_back(inputa);
		cin>>inputa;
	}
	sort(grade.begin(),grade.end());
	vector<int>::iterator run;
	run=grade.begin();
	for(int i=0;i<100;i+=10){
		int counter=0;
		while((*run)/10 == i/10){
			counter++;
			run++;
		}
		cout<<counter<<" ("<<i<<","<<i+9<<")\n";
	}
	if(grade.end()-run){
		cout<<grade.end()-run<<" 100\n";
	}
	return 0;
}