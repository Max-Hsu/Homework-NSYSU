#include <iostream>
#include <string>
#include "ch7-11.h"
#include <vector>

Play::Play(string Iname,int Iscore):name(Iname),score(Iscore){}
void Play::Output(){
	cout<<name<<" "<<score<<"\n";
}
void Play::OutputWithName(){
	cout<<"The score for "<<name<<" is "<<score<<"\n";
}
int Play::search(string find){
	if(name==find){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char choice;
	string findN;
	int status=1;
	vector<class Play> whole;
	cout<<"Enter an option\na. Add new player and score.\n"\
	"b. Print all players and scores.\nc. Search for player's score.\n"\
	"d. Remove a player.\ne. Quit.\n";
	cin>>choice;
	while(choice>='a'&&choice<='d'){
		switch(choice){
			case 'a':
				if(whole.size()>=10){
					cout<<"Sorry the space is full\n";
				}
				else{
					string nName;
					int nScore;
					cout<<"Enter new player name.\n";
					cin>>nName;
					cout<<"Enter new player score.\n";
					cin>>nScore;
					class Play nPlay(nName,nScore);
					whole.push_back(nPlay);
				}
				break;
			case 'b':
				for(vector<class Play>::iterator run=whole.begin();run<whole.end();run++){
					(*run).Output();
				}
				break;
			case 'c':
				findN="\0";
				status=1;
				cout<<"What player to search for?\n";
				cin>>findN;
				for(vector<class Play>::iterator run=whole.begin();run<whole.end();run++){
					if((*run).search(findN)){
						(*run).OutputWithName();
						status=0;
						break;
					}
				}
				if(status){
					cout<<"Player "<<findN<<" not found.\n";
				}
				break;
			case 'd':
				findN="\0";
				status=1;
				cout<<"What player to remove?\n";
				cin>>findN;
				for(vector<class Play>::iterator run=whole.begin();run<whole.end();run++){
					if((*run).search(findN)){
						whole.erase(run);
						status=0;
						cout<<"Player "<<findN<<"is erased.\n";
						break;
					}
				}
				if(status){
					cout<<"Player "<<findN<<" not found.\n";
				}
				break;
		}
		
		cout<<"\n\nEnter an option\na. Add new player and score.\n"\
		"b. Print all players and scores.\nc. Search for player's score.\n"\
		"d. Remove a player.\ne. Quit.\n";
		cin>>choice;
	}
	
	return 0;
}