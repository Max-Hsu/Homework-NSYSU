#include<iostream>

using namespace std;

int main(){
	char option1,option2;
	int wincounter1=0;
	int wincounter2=0;
	char choice;

	do{
	cout<<"Please enter either R)ock P)aper or S)cissors.";
	cin>>option1;
	cout<<"Please enter either R)ock P)aper or S)cissors.";
	cin>>option2;
	switch(option1){
		case 'R':
			if(option2=='R'){
				cout<<"no winner"<<endl;
			}
			else if(option2=='P'){
				cout<<"player 2 is winner"<<endl;
				wincounter2++;
			}
			else{
				cout<<"player 1 is winner"<<endl;
				wincounter1++;
			}
		break;
		case 'P':
			if(option2=='P'){
				cout<<"no winner"<<endl;
			}
			else if(option2=='S'){
				cout<<"player 2 is winner"<<endl;
				wincounter2++;
			}
			else{
				cout<<"player 1 is winner"<<endl;
				wincounter1++;
			}
		break;
		case 'S':
			if(option2=='S'){
				cout<<"no winner"<<endl;
			}
			else if(option2=='R'){
				cout<<"player 2 is winner"<<endl;
				wincounter2++;
			}
			else{
				cout<<"player 1 is winner"<<endl;
				wincounter1++;
			}
		break;
	}
	cout<<"Total to this move"<<endl;
	cout<<"Player 1  "<<wincounter1<<endl;
	cout<<"Player 2  "<<wincounter2<<endl;
	
	cout<<"do you want to continue?"<<endl;
	cin>>choice;
	}while(choice=='Y'||choice=='y');
}