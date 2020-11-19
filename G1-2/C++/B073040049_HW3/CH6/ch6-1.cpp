#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct rating{
	int Num;
	int Core;
	int Performance;
	int Ideation;
};
int main(){
	fstream file;
	int iter=0;
	struct rating worker[10];
	string trash;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	file.open("CH6_01_data.txt",fstream::in);
	getline(file,trash);
	while(!file.eof()){
	file>>worker[iter].Num>>worker[iter].Core>>worker[iter].Performance>>worker[iter].Ideation;
	iter++;
	}
	cout<<"Number\t\tTotal\t\tPoint\n";
	for(int i=0;i<iter;i++){
		float Total=(worker[i].Core*0.5/10+worker[i].Performance*0.3/30+worker[i].Ideation*0.2/10)*100;
		cout<<worker[i].Num<<"\t\t"<<Total<<"\t\t";
		if(Total>=80){
			cout<<"1\n";
		}
		else if(Total>=60){
			cout<<"2\n";
		}
		else if(Total>=50){
			cout<<"3\n";
		}
		else{
			cout<<"4\n";
		}
	file.close();
	}
	return 0;
}