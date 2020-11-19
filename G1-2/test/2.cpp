#include <iostream>

using namespace std;
void ps(int asd[],int as,int sd){
	for(int i=0;i<as;i++){
		for(int j=0;j<sd;j++){
			cout<<asd[as*sd+sd]<<" ";
		}
	}
}
int main(){
	int sosi[2][2]={1};
	ps(sosi,2,2);

	return 0;
}