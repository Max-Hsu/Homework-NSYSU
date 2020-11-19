#include <iostream>
using namespace std;
int win[4]={0};
int check(int pos,int num){
	for(int i=0;i<pos+1;i++){
		if(num==win[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	srand(time(NULL));
	for(int i=0;i<4;i++){
		int randa=rand()%35+1;
		while(check(i,randa)){
		randa=rand()%35+1;
		}
		win[i]=randa;
	}
	cout<<"The four winners are: "<<endl;
	for(int i=0;i<4;i++){
		cout<<win[i]<<" ";
	}
	cout<<endl;
	return 0;
}