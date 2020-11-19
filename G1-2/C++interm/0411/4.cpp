#include <iostream>

using namespace std;
class money{
	int hour[7]={0};
	public:
	void count();
	void in();
};
void money::in(){
	for(int i=0;i<7;i++){
		cout<<"Day "<<i+1<<" :\n";
		cin>>hour[i];
	}
}
void money::count(){
	double unit;
	for(int i=0;i<7;i++){
		if(hour[i]>10){
			unit+=(hour[i]-10)*1.66;
			hour[i]-=(hour[i]-10);
		}
		if(hour[i]>8){
			unit+=(hour[i]-8)*1.33;
			hour[i]-=(hour[i]-8);
		}
		unit+=8;
	}
	cout<<"Your total working units : "<<unit<<"\nYour salary : "<<unit*140<<"\n";
}
int main(){
	money aa;
	aa.in();
	aa.count();
	return 0;
}