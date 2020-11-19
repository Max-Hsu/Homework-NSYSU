#include <iostream>
#include <fstream>
#include <string>
using namespace std;
	string name[10];
	int score[10];
	int counter=0;
	int total_score=0;
	int average=0;
int getPlayerScore(string namea){
	for(int i=0;i<counter;i++){
		if(namea==name[i]){
			return score[i];
		}
	}
	return 0;
}
void decide(int scorea){
	if(scorea>average){
		cout<<" is higher than average"<<endl;
	}
	else if(scorea==average){
		cout<<" is equal to average."<<endl;
	}
	else{
		cout<<" is lower than average"<<endl;
	}
}
int main(){
	fstream file;
	file.open("scores.txt",fstream::in);
	while(!file.eof()){
	file>>name[counter];
	file>>score[counter];
	counter++;
	}
	for(int i=0;i<counter;i++){
		total_score+=score[i];
	}
	average=total_score/counter;
	cout<<"Average is "<<average<<endl;
	file.close();
	while(1){
		string name;
		cout<<"Please enter player's name : ";
		cin>>name;
		int ans=getPlayerScore(name);
		if(ans){
			cout<<name<<" : "<<ans;
			decide(ans);
		}
		else{
			cout<<"The player is not found in the file"<<endl;
		}
	}
}