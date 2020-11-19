#include <iostream>
#include <stdlib.h>
using namespace std;
int humanTurn(int humanTotalScore){
	int counter=0;
	char typed;
	cout<<"is your turn enter 'r' to roll."<<endl;
	cin>>typed;
	while(typed=='r'){
		typed='a';
		int rolled=rand()%6+1;
		if(rolled!=1){
			counter+=rolled;
		cout<<"You rolled "<<rolled<<endl<<"Your score this round is : "<<counter<<endl;
		cout<<"If you hold , your total score would be : "<<counter+humanTotalScore<<endl;
		cout<<"Press 'h' to hold or 'r' to roll again."<<endl;
		cin>>typed;
		}
		else{
			counter=0;
			cout<<"You rolled "<<rolled<<endl<<"you lost this round adding 0 to total score"<<endl;
			return 0;
		}
	}
	return counter;
	
}
int computerTurn(int computerTotalScore){
	int counter=0;
	int status=0;
	cout<<"It is the computer's turn!"<<endl;
	while (counter<20){
		int rolled=rand()%6+1;
		cout<<"the computer rolled "<<rolled<<endl;
		if(rolled!=1){
			counter+=rolled;
			cout<<"the computer score this round"<<counter<<endl;
			cout<<"If the computer holds, its total score would be "<<counter+computerTotalScore<<endl;
			status=0;
		}
		else{
			cout<<"No add score this round"<<endl;
			counter=0;
			status=1;
			cout<<"enter 'c' to continue"<<endl;
			return 0;
		}
	}
	if(!status){
		cout<<"The computer holds .\t Enter 'c' to continue."<<endl;
	}
	return counter;
}
int main(){
	srand(time(NULL));
	int playerscore=0;
	int computerscore=0;
	char typed;
	while(playerscore<100&&computerscore<100){
		playerscore+=humanTurn(playerscore);
		if(playerscore>=100){
			cout<<"you win!!!"<<endl;
			break;
		}
		computerscore+=computerTurn(computerscore);
		if(computerscore>=100){
			cout<<"sorry the computer won"<<endl;
			break;
		}
		cin>>typed;
		if(typed!='c'){
			break;
		}
	}
	return 0;
}