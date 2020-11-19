#include <iostream>
#include <string>

using namespace std;
string l="love";
string L="Love";
int main(){
	string input;
	bool big=false;
	char acontinue='y';
	bool first=true;
	while(acontinue=='y'){
	cout<<"input :";
	if(!first){
	getline(cin,input);
	}
	getline(cin,input);
	first=false;
	string::iterator start=input.begin();
	string::iterator end=input.begin();
	for(string::iterator run=input.begin();run<input.end();run++){
		if((*run)>='A' &&(*run)<='Z'){
			end=run;
			if(run==start){
				big=true;
			}
		}
		else if((*run)>='a' &&(*run)<='z'){
			end=run;
		}
		else{
			if((end-start)==3){
				if(big){
					input.erase(start,end+1);
					input.insert(size_t(start-input.begin()),L);
				}
				else if(!big){
					input.erase(start,end+1);
					input.insert(size_t(start-input.begin()),l);
				}
			}
			start=(run+1);
			big=false;
		}
	}
	if((end-start)==3){
		if(big){
			input.erase(start,end+1);
			input.insert(size_t(start-input.begin()),L);
		}
		else if(!big){
			input.erase(start,end+1);
			input.insert(size_t(start-input.begin()),l);
		}
	}
	cout<<input<<"\n";
	cout<<"Do you want to continue?(y or n) : ";
	cin>>acontinue;
	}
	return 0;
}