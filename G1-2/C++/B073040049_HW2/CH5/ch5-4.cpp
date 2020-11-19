#include <iostream>

using namespace std;

int main(){
	char s='\0';
	int count_a=0;
	int count_e=0;
	int count_i=0;
	int count_o=0;
	int count_u=0;
	
	cout<<"please input the string : ";
	cin.get(s);
	while(s != '\n'){
		switch(s){
			case 'a':
				count_a++;
				break;
			case 'e':
				count_e++;
				break;
			case 'i':
				count_i++;
				break;
			case 'o':
				count_o++;
				break;
			case 'u':
				count_u++;
				break;
		}
		cin.get(s);
	}
	cout<<"Vowel\t\tCount"<<endl;
	cout<<"a\t\t"<<count_a<<"\n"<<"e\t\t"<<count_e<<"\n"<<"i\t\t"<<count_i<<"\n"<<"o\t\t"<<count_o<<"\n"<<"u\t\t"<<count_u<<endl;
	return 0;
}