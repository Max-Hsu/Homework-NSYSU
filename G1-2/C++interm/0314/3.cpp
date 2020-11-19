#include <iostream>

using namespace std;

int fun(int num){
if(num==1){
return 1;}
else if(num==2){
return 1;}
else{
return fun(num-1)+fun(num-2);}
}
int main(){
	for(int i=1;i<=20;i++){
		cout<<fun(i)<<endl;
	}
	
}