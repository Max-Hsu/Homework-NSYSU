#include <iostream>
#include <vector>

using namespace std;
int main(){
	int num;
	vector<int> line;
	vector<int>::iterator run;
	cout<<"Enter the number of suiters\n";
	cin>>num;
	for(int i=1;i<=num;i++){
		line.push_back(i);
	}
	run=line.begin();
	while(line.size()>1){
		run+=2;
		while(run>=line.end()){
			run=line.begin()+(run-line.end());
		}
		line.erase(run);
	}
	cout<<"To win the princess, you should stand in position "<<line[0]<<"\n";
	return 0;
}