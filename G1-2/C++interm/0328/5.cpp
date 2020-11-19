#include <iostream>
using namespace std;

int main(){
	char mine[7][7]={'\0'};
	char play[7][7]={'\0'};
	int display[7][7]={0};
	for(int i=0;i<20;i++){
		int a=rand()%5+1;
		int b=rand()%5+1;
			while(mine[a][b]=='X'){
				a=rand()%5+1;
				b=rand()%5+1;
			}
		mine[a][b]='X';
	}
	for(int i=1;i<6;i++){
		for(int j=0;j<6;j++){
			if(mine[i][j]!='X')
				mine[i][j]='O';
		}
	}
	
	for(int i=1;i<6;i++){
		for(int j=0;j<6;j++){
			int counter_formine=0;
			if(mine[i][j]=='O'){
				for(int q=-1;q<2;q++){
					for(int w=-1;w<2;w++){
						if(mine[i+q][j+w]=='X'){
							counter_formine++;
						}
					}
				}
				play[i][j]=counter_formine;
			}
		}
	}
		for(int i=1;i<6;i++){
				for(int j=1;j<6;j++){
					cout<<mine[i][j]<<"  ";
				}
				cout<<"\n";
			}

	int counterq=0;
	int status=1;
	while(counterq<5){
		int choice=0;
		int x,y=0;
		cout<<"Choose the above options \n(1:mine 2:exit)\n";
		cin>>choice;
		if(choice==2){
			status=0;
			break;
		}
		cout<<"Enter (x,y)\n";
		cin>>x>>y;
		//cout<<"min "<<mine[x][y];
		if(mine[x][y]=='X'){
			cout<<"You died!!"<<endl;
			status=0;
			break;
		}
		else{
			display[x][y]=play[x][y];
			for(int i=1;i<6;i++){
				for(int j=1;j<6;j++){
					cout<<display[i][j]<<"  ";
				}
				cout<<"\n";
			}
		}
		counterq++;
	}
	
	if(status){
		cout<<"Congratulation"<<endl;
	}
	
	
	
	return 0;
}