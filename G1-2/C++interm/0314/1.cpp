#include <iostream>

using namespace std;
int main(){
	for(int i=0;i<10;i++){
	char word=65+rand()%26;
	cout<<word;
	}
	cout<<endl;
	return 0;
}