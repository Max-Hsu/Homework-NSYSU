#include <iostream>

using namespace std;
struct Grade{
	int score[5];
};
int checkx(Grade check){
	cout<<"Finish intime : ";
	for(int i=0;i<5;i++){
		if(check.score[i]==0){
			cout<<"0\n";
			return 1;
		}
	}
	cout<<"1\n";
	return 0;

}
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
double avg_element(Grade a){
	double adder;
	for(int i=0;i<5;i++){
		adder+=a.score[i];
	}
	cout<<"Average : "<<adder/5<<",";
}
double min_element(Grade a){
	int min;
	min=a.score[0];
	for(int i=1;i<5;i++){
		if(min>a.score[i]){
			min=a.score[i];
		}
	}
	cout<<"Min : "<<min<<"\n";
}
double max_element(Grade a){
	int max;
	max=a.score[0];
	for(int i=1;i<5;i++){
		if(max<a.score[i]){
			max=a.score[i];
		}
	}
	cout<<"Max : "<<max<<",";
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
	if(!checkx(AGrade)){
	avg_element(AGrade);
	max_element(AGrade);
	min_element(AGrade);
	}
	
	return 0;
}