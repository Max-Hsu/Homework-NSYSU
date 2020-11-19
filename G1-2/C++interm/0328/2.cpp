#include <iostream>

using namespace std;
int main(){
	char book[10][10]={'\0'};
	book[0][0]='X';
	book[0][1]='X';
	book[1][0]='X';
	book[1][1]='X';
	book[0][8]='X';
	book[0][9]='X';
	book[1][8]='X';
	book[1][9]='X';
	book[8][8]='X';
	book[8][9]='X';
	book[9][8]='X';
	book[9][9]='X';
	book[8][0]='X';
	book[8][1]='X';
	book[9][0]='X';
	book[9][1]='X';
	int row;
	int col;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<book[i][j];
			}
			cout<<"\n";
		}
	cout<<"row:";
	cin>>row;
	cout<<"col:";
	cin>>col;
	while(row!=-1&&col!=-1){
		while(book[row][col]=='X'||book[row][col]=='O'){
			
			cout<<"Booking error\n";
			
			cout<<"row:";
			cin>>row;
			cout<<"col:";
			cin>>col;
			if(row==-1){
				break;
			}
		}
		book[row][col]='O';
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout<<book[i][j];
			}
			cout<<"\n";
		}
		
		
		
	cout<<"row:";
	cin>>row;
	cout<<"col:";
	cin>>col;
	}
	
	
	return 0;
}