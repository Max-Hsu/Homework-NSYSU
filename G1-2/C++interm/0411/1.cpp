#include <iostream>

using namespace std;
struct Grade{
	int score[5];
};
void check(Grade check){
	cout<<"Finish intime : ";
	for(int i=0;i<5;i++){
		if(check.score[i]==0){
			cout<<"0\n";
			return;
		}
	}
	cout<<"1\n";
}
int main(){
	Grade AGrade;
	
	cout<<"Initial struct , scores : ";
	for(int i=0;i<5;i++){
		AGrade.score[i]=0;
		cout<<AGrade.score[i];
		if(i<4){
			cout<<",";
		}
		
	}
	cout<<"\n";
	check(AGrade);
	cout<<"Please Key in score : ";
	for(int i=0;i<5;i++){
		cin>>AGrade.score[i];
	}
	cout<<"student scores :";
	for(int i=0;i<5;i++){
		cout<<AGrade.score[i];
		if(i<4){
			cout<<",";
		}
	}
	cout<<"\n";
	check(AGrade);
	return 0;
}