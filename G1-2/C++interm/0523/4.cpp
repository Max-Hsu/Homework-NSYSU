#include<iostream>

using namespace std;
struct queue{
	int num;
	queue *before;
};
int main(){
	queue *pointer = nullptr;
	queue *first = nullptr;
	int option;
	cout<<"1 for push , 2 for pop ,3 for exit\n";
	cin>>option;
	while(option==1 || option ==2){
		if(option == 1){
			int num;
			cout<<"please input number : ";
			cin>>num;
			queue *temp;
			temp = new queue;
			temp->num=num;
			if(pointer == nullptr){
				temp->before=nullptr;
				pointer=temp;
				first=temp;
			}
			else{
				pointer->before=temp;
				temp->before=nullptr;
				pointer=temp;
			}
		}
		else if(option == 2){
			if(first==nullptr){
				cout<<"there is no element in the queue\n";
			}
			else{
				queue *temp=first;
				cout<<temp->num<<"\n";
				first=temp->before;
				delete temp;
			}
		}
		cout<<"1 for push , 2 for pop ,3 for exit\n";
		cin>>option;
	}
	return 0;
}