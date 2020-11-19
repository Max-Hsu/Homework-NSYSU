#include<iostream>

using namespace std;

int main(){
	int row,column;
	int arra[100][100];
	cin>>row>>column;
	double **arr;
	arr = new double*[row];
	for(int i=0;i<row;i++){
		arr[i] = new double[column];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cin>>arr[i][j];
			arra[i][j]=arr[i][j];
		}
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<arr[i][j]<<" at "<<&arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<arra[i][j]<<" at "<<&arra[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	return 0;
}