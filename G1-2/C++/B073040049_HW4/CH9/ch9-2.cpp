#include <iostream>
#include <string>
using namespace std;
int zero=48;
int main(){
	string input;
	cout<<"When enter a single \"-1\" in one line this program will end\n";
	getline(cin,input);
	while(input!="-1"){
		for(int i=0;i<int(input.size());i++){
			if(input[i]>='A' && input[i]<='W'){
				input[i]+=3;
			}
			else if(input[i]>='X' && input[i]<='Z'){
				input[i]-=(26-3);
			}
			else if(input[i]>='a' && input[i]<='w'){
				input[i]+=3;
			}
			else if(input[i]>='x' && input[i]<='z'){
				input[i]-=(26-3);
			}
			else if(input[i]>='0' && input[i]<='9'){
				input[i]=char(((int(input[i])-zero)+5)%10+zero);
			}
			else if(input[i]==' '){
				input.erase(input.begin()+i);
				i-=1;
			}
			else{
				input[i]=' ';
			}
		}
		cout<<input<<"\n";
		getline(cin,input);
	}
	return 0;
}