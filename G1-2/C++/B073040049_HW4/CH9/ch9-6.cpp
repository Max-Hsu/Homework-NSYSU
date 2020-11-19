#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class music{
	public:
		music(string iauthor,string iname);
		string returnAuthor();
		void standOutput();
	private:
		string author,name;
};
music::music(string iauthor,string iname):
author(iauthor),name(iname)
{}
string music::returnAuthor(){
	return author;
}
bool comparer(music& compare1,music& compare2){
	return ((compare1.returnAuthor())<(compare2.returnAuthor()));
}
void music::standOutput(){
	cout<<author<<" - "<<name;
}
int main(){
	int counter=0;
	string list[100];
	string list_ar[100];
	fstream file;
	file.open("list.txt",fstream::in);
	while(!file.eof()){
		getline(file,list[counter]);
		counter++;
	}
	for(int i=0;i<counter;i++){
		list[i].erase(0,3);
		int place=list[i].find(" - ");
		size_t backcheck=list[i].find('\r');
		while(backcheck != string::npos){
			list[i].erase(backcheck);
			backcheck=list[i].find('\r');
		}
		list[i].erase(place,3);
		list_ar[i]=list[i].substr(place);
		list[i].erase(list[i].begin()+place,list[i].end());
		/*
		cout<<list[i]<<"\n";
		cout<<list_ar[i]<<"\n";
		*/
	}
	vector<class music> v_list;
	for(int i=0;i<counter;i++){
		v_list.push_back(music(list_ar[i],list[i]));
	}
	sort(v_list.begin(),v_list.end(),comparer);
	for(vector<class music>::iterator run=v_list.begin();run<v_list.end();run++){
		cout<<(run-v_list.begin()+1)<<". ";
		(*run).standOutput();
		cout<<"\n";
	}
	return 0;
}