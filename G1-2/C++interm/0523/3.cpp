#include<iostream>

using namespace std;
struct stack{
	int num;
	stack *next;
};
int main(){
	stack *pointer = nullptr;
	int option;
	cout<<"1 for push , 2 for pop ,3 for exit\n";
	cin>>option;
	while(option==1 || option ==2){
		if(option == 1){
			int num;
			cout<<"please input number : ";
			cin>>num;
			stack *temp;
			temp = new stack;
			temp->num=num;
			if(pointer == nullptr){
				temp->next=nullptr;
				pointer=temp;
			}
			else{
				temp->next=pointer;
				pointer=temp;
			}
		}
		else if(option == 2){
			if(pointer==nullptr){
				cout<<"there is no element in the stack\n";
			}
			else{
				stack *temp=pointer;
				cout<<temp->num<<"\n";
				pointer=temp->next;
				delete temp;
			}
		}
		cout<<"1 for push , 2 for pop ,3 for exit\n";
		cin>>option;
	}
	return 0;
}