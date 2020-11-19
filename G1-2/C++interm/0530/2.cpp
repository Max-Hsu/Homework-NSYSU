#include <iostream>

using namespace std;

int main(){
	int row,col,nonz;
	cout<<"Enter row and column\n";
	cin>>row>>col;
	cout<<"Non-zero number?\n";
	cin>>nonz;
	int **lista;
	lista = new int * [row];
	for(int i=0;i<row;i++){
		lista[i] = new int [col];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			lista[i][j]=0;
		}
	}
	for(int i=0;i<nonz;i++){
		int rowa=rand()%row;
		int cola=rand()%col;
		while(lista[rowa][cola]){
			rowa=rand()%row;
			cola=rand()%col;
		}
		lista[rowa][cola]=rand()%100;
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<lista[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<row<<"\t"<<col<<"\t"<<nonz<<"\n";
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(lista[i][j]!=0){
				cout<<i<<"\t"<<j<<"\t"<<lista[i][j]<<"\n";
				
			}
		}
	}
	return 0;
}