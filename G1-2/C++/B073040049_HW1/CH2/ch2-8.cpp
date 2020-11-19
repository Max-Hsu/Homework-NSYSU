#include <iostream>
using namespace std;

int main(){
	int F=0;
	int C=101;
	do{
		C--;
		F=C*9/5+32;
	}while(C!=F);
	cout<<"The temperature is the same at "<<C<<endl;
	return 0;
}