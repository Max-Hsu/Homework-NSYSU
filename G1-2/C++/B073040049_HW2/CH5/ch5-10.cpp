#include <iostream>
#include <string>
using namespace std;

int main(){
	string flavor[5]={"Chocolate","Vanilla","Strawberry","Raspberry","Butterscotch"};
	string choice;
	char toContinue='Y';
	int numberOfIce;
	int left[5]={20,15,15,20,20};
	int buy[5]={0};
	cout<<"Code\t\tFlavor\n"<<"1\t\tChocolate\n"<<"2\t\tVanilla\n"<<"3\t\tStrawberry\n"<<"4\t\tRaspberry\n"<<"5\t\tButterscotch"<<endl;
	while(toContinue=='Y'){
	cout<<"The product remain in the stock"<<endl;
	for(int i=0;i<5;i++){
		cout<<i+1<<"\t\t"<<left[i]<<endl;
	}
	cout<<"choose which flavor and numbers of it : ";
	cin>>choice;
	cin>>numberOfIce;
	for(int i=0;i<5;i++){
		if(choice==flavor[i]){
			if(numberOfIce>left[i]){
				cout<<"the "<<flavor[i]<<" flavor icecream is not enough."<<endl;
				break;
			}
			else{
				left[i]-=numberOfIce;
				buy[i]+=numberOfIce;
				break;
			}
		}
	}
	cout<<"Continue choice ?(Y/N)";
	cin>>toContinue;
	}
	cout<<"\nthe user's cart"<<endl;
	for(int i=0;i<5;i++){
		if(buy[i]>0){
			cout<<"\t\t"<<flavor[i]<<"\t\t"<<buy[i]<<endl;
		}
	}
	return 0;
}