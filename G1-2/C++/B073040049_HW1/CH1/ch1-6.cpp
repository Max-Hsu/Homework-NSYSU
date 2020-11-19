#include <iostream>

using namespace std;

int main(int argc,char *argv[]){
int distance;
int time;
float money;
if(argc !=3){
	cout<<"please input \"distance\" and \"duration\":";
	cin>> distance >> time;
	}
else{
	distance=atoi(argv[1]);
	time=atoi(argv[2]);
	}
if(distance<=2){
money=2;
	}
else if(distance<=8){
money=2+(distance-2)*0.5;
	}
else{
money=5+(distance-8)*1;
}
money+=time*0.2;

cout<<"money to charge:"<<money<<endl;

return 0;
}