#include <iostream>
#include "ch10-1.h"

using namespace std;

int main(){
	int cRow,cColumn;
	cout<<"Enter the row and column dimensions of the array\n";
	cin>>cRow>>cColumn;
	class TwoD test(cRow,cColumn);
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			double input;
			cin>>input;
			test.set(i,j,input);
		}
	}
	cout<<"Echoing the 2 dimension array , matrix1\n";
	test.returnsize();
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			cout<<test.get(i,j)<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"Enter the row and column dimensions of the array\n";
	cin>>cRow>>cColumn;
	class TwoD test2(cRow,cColumn);
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			double input;
			cin>>input;
			test2.set(i,j,input);
		}
	}
	cout<<"Echoing the 2 dimension array , matrix2\n";
	test2.returnsize();
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			cout<<test2.get(i,j)<<" ";
		}
		cout<<"\n";
	}
	
	class TwoD test3;
	test3=test2;
	cout<<"assigning matrix2 to matrix3\n";
	test3.returnsize();
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			cout<<test3.get(i,j)<<" ";
		}
		cout<<"\n";
	}
	cout<<"Displaying the 2 dimension array , sum of matrix 1 and matrix 2\n";
	class TwoD test4(test+test2);
	test4.returnsize();
	for(int i=0;i<cRow;i++){
		for(int j=0;j<cColumn;j++){
			cout<<test4.get(i,j)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}