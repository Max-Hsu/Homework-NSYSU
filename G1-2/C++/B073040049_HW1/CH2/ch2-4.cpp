#include <iostream>
using namespace std;

int main(){
	int status=0;
	for(int i=3;i<=100;i++){
		status=0;
		for(int j=2;j<=i/2;j++){
			if(i%j==0){
				status=1;
				break;
			}
		}
		if(!status){
			cout<<i<<" is a prime number."<<endl;
		}
	}
	return 0;
}