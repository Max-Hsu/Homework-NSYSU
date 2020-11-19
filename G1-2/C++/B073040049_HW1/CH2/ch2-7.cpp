#include <iostream>
using namespace std;

int main(){
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	char scoreGrade[]={'S','A','B','C','D','E','F'};
	int scorePoint[]={10,9,8,7,6,5,0};
	int numberOfTest=0;
	float totalPoint=0;
	cout<<"Input the number of subjects:";
	cin>>numberOfTest;
	for(int i=0;i<numberOfTest;i++){
		char grade;
		cout<<"Score received for subject "<<i+1<<" :";
		cin>>grade;
		for(int j=0;j<7;j++){
			if(scoreGrade[j]==grade){
				totalPoint+=scorePoint[j];
			}
		}
	}
	cout<<"The average of the grade points "<<totalPoint/numberOfTest<<endl;
	return 0;
}