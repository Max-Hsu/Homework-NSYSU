#include <iostream>

using namespace std;
int calc(int start_time,int end_time){
	start_time+=2400;
	end_time+=2400;
	int ans=(end_time-start_time)/100*60+(end_time-start_time)%100;
	if(ans>=1440){
		ans=-1;
	}
	return ans;
}

int main(){
	int start_time,end_time;
	char choice='y';
	while(choice=='y'){
	cout<<"Please input start time and end time : ";
	cin>>start_time;
	cin>>end_time;
	int ans=calc(start_time,end_time);
	if(ans!=-1){
		cout<<"The time difference between "<<start_time<<" and "<<end_time\
		<<" is "<<ans<<" minutes "<<endl;
	}
	else{
		cout<<"The time is error"<<endl;
	}
	cout<<"Do you want to continue?? (y/n)"<<endl;
	cin>>choice;
	}
	return 0;
}