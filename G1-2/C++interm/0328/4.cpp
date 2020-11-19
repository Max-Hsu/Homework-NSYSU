#include <iostream>

using namespace std;
char check_win(char q[][3]){
	int ans=0;
	char check_now;
	int aaa[]={(q[0][0]==q[0][1])+(q[0][1]==q[0][2]),(q[1][0]==q[1][1])+(q[1][1]==q[1][2]),\
	(q[2][0]==q[2][1])+(q[2][1]==q[2][2]),(q[0][0]==q[1][0])+(q[1][0]==q[2][0]),(q[0][1]==q[1][1])+(q[1][1]==q[2][1]),\
	(q[0][2]==q[1][2])+(q[1][2]==q[2][2]),(q[0][0]==q[1][1])+(q[1][1]==q[2][2]),(q[0][2]==q[1][1])+(q[1][1]==q[2][0])};
	//cout<<"i want"<<(q[0][0]==q[1][0])+(q[1][0]==q[2][0])<<endl;
	for(int i=0;i<8;i++){
		//cout<<aaa[i]<<" ";
		if(aaa[i]>=2){
			if(i<3){
				return q[i][0];
			}
			else if(i<6){
				return q[0][i-3];
			}
			else{
				return q[1][1];
			}
		}
	}
	return 'q';
}
int main(){
	char cross[3][3]={'0','1','2','3','4','5','6','7','8'};
	int round=0;
	int choice;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<cross[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(1){
		round++;
		cout<<"round "<<round<<"\nPlayer:"<<endl;
		cin>>choice;
		cross[choice/3][choice%3]='O';
		int C_choice=rand()%9;
		while(cross[C_choice/3][C_choice%3]=='O'||cross[C_choice/3][C_choice%3]=='X'){
			C_choice=rand()%9;
		}
		cross[C_choice/3][C_choice%3]='X';
		for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<cross[i][j]<<" ";
		}
		cout<<"\n";
		}
		if(check_win(cross)!='q'){
		if(check_win(cross)=='O'){
			cout<<"You win!!"<<endl;
			break;
		}
		else if(check_win(cross)=='X'){
			cout<<"You lose!!"<<endl;
			break;
		}
	}
	}

	return 0;
}