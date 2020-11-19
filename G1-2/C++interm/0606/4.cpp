#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream A;
	fstream B;
	fstream OUT;
	int num[100];
	int counter=0;
	A.open("seq1.txt",fstream::in);
	B.open("seq2.txt",fstream::in);
	OUT.open("merge.txt",fstream::out);
	while(!A.eof()){
		A>>num[counter];
		counter++;
	}
	counter--;

	while(!B.eof()){
		B>>num[counter];
		counter++;
	}
	counter--;
	cout<<counter<<"\n";
	for(int i=0;i<counter;i++){
		for(int j=0;j<counter;j++){
			if(num[i]<num[j]){
				int temp=num[j];
				num[j]=num[i];
				num[i]=temp;
			}
		}
	}
	for(int i=0;i<counter;i++){
		OUT<<num[i]<<"\n";
	}
	A.close();
	B.close();
	OUT.close();
	return 0;
}