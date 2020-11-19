#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream right;
	fstream my;
	char Cright[10];
	char Cmy[10];
	int counter = 0;
	int total = 0;
	right.open("TrueAnswer.txt",fstream::in);
	my.open("MyAnswer.txt",fstream::in);
	while((!right.eof())&&(!my.eof())){
		right>>Cright[counter];
		my>>Cmy[counter];
		if(Cright[counter]==Cmy[counter]){
			total+=10;
		}
		counter++;
	}
	cout<<"Start reading true answers and your answers ...\n";
	cout<<"\nQuestion answer is : \t";for(int i=0;i<10;i++){cout<<Cright[i]<<" ";}
	cout<<"\nYour answer is :\t";for(int i=0;i<10;i++){cout<<Cmy[i]<<" ";}
	cout<<"\nYour score is :" <<total<<"\n";
	return 0;
}