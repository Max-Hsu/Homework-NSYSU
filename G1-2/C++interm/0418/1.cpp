#include <iostream>
#include "1.h"
#include <vector>
using namespace std;
stu::stu(){}
stu::stu(string departmenta,string namea,string studentIDa,string gendera)
:department(departmenta),name(namea),studentID(studentIDa),gender(gendera){}

void stu::setData(string departmenta,string namea,string studentIDa,string gendera){
	department=departmenta;
	name=namea;
	studentID=studentIDa;
	gender=gendera;
}
void stu::OutputData(){
	cout<<"The result : \n";
	cout<<"department : "<<department<<"\n";
	cout<<"name : "<<name<<"\n";
	cout<<"studentID : "<<studentID<<"\n";
	cout<<"gender : "<<gender<<"\n";
}

int main(){
	string departmentaa;
	string nameaa;
	string studentIDaa;
	string genderaa;
	vector <class stu> all;
	cout<<"(Enter [exit] to leave)\n";
	cout<<"Enter your department : \n";
	cin>>departmentaa;
	while(departmentaa != "exit"){
		cout<<"Enter your Name : \n";
		cin>>nameaa;
		cout<<"Enter your Student ID : \n";
		cin>>studentIDaa;
		cout<<"Enter your gender : \n";
		cin>>genderaa;
		class stu nStudent;
		nStudent.setData(departmentaa,nameaa,studentIDaa,genderaa);
		all.push_back(nStudent);
		cout<<"Enter your department : \n";
		cin>>departmentaa;
	}
	for(vector<class stu>::iterator run=all.begin();run<all.end();run++){
		(*run).OutputData();
	}
}
