#include <iostream>
#include <string>

using namespace std;

int main(){
	string * lista;
	int counter=5;
	lista = new string [counter];
	lista[0]="ad";
	lista[1]="qad";
	lista[2]="a5d";
	lista[3]="a687d";
	lista[4]="2sad";
	string choice;
	cout<<"print initial name list\n";
	while(true){
		for(int i=0;i<counter;i++){
			cout<<i<<"\t"<<lista[i]<<"\n";
		}
		cout<<"add\tdelete\texit\t";
		cin>>choice;
		if(choice=="add"){
			string *listt;
			listt = new string [++counter];
			for(int i=0;i<counter-1;i++){
				listt[i]=lista[i];
			}
			cout<<"Please enter the name:\n";
			cin>>listt[counter-1];
			lista=listt;
		}
		else if(choice=="delete"){
			string name;
			cout<<"Please enter the name\n";
			cin>>name;
			bool found=false;
			int i;
			for(i=0;i<counter;i++){
				if(lista[i]==name){
					found=true;
					break;
				}
			}
			if(found){
				string * listt;
				listt = new string [--counter];
				for(int j=0;j<i;j++){
					listt[j]=lista[j];
				}
				for(;i<counter;i++){
					listt[i]=lista[i+1];
				}
				lista=listt;
			}
			else{
				cout<<name<<" not found\n";
			}
		}
		else{
			break;
		}
	}
	
	return 0;
}