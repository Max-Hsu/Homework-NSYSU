#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
const int numToGenerate = 100;
const int passwordLength = 20;
int main(){
	fstream passwordOutput;
	passwordOutput.open("Data.txt",fstream::out);
	srand(time(0));
	for(int i=0;i<numToGenerate;i++){
		for(int j=0;j<passwordLength;j++){
			passwordOutput<<rand()%10;
		}
		passwordOutput<<"\n";
	}
	passwordOutput.close();
	
	char input;
	int numCounter[10]={0};
	passwordOutput.open("Data.txt",fstream::in);
	while(!passwordOutput.eof()){
	passwordOutput.get(input);
	numCounter[int(input-'0')]++;
	while (input != '\n'){
		passwordOutput.get(input);
	}
	}
	for(int i=0;i<10;i++){
		cout<<i<<"\t\t"<<double(numCounter[i])/numToGenerate<<"\n";
	}
	passwordOutput.close();
	return 0;
}