#include <iostream>
#include <vector>
#include <string>
using namespace std;
class trivia{
	public:
		trivia(string iquestion,string ianswer,int ivalue);
		bool operator == (string aanswer);
		string returnTanswer();
		int returnEarnMoney();
		friend ostream& operator << (ostream& outputs,const trivia& Out);
	private:
		string question;
		string answer;
		int value;
};
trivia::trivia(string iquestion,string ianswer,int ivalue):
question(iquestion),answer(ianswer),value(ivalue)
{}

bool trivia::operator == (string aanswer){
	return (aanswer == answer);
}
string trivia::returnTanswer(){
	return answer;
}
int trivia::returnEarnMoney(){
	return value;
}
ostream& operator << (ostream& outputs,const trivia& Out){
	outputs<<Out.question;
	return outputs;
}
int main(){
	vector<class trivia> qs;
	qs.push_back(trivia("Year that Amelia Earhart disappered?","1938",5));
	qs.push_back(trivia("Which season that the children will growth faster?","spring",2000));
	qs.push_back(trivia("Can human keep the eyes open when sneezeing?","no",250));
	qs.push_back(trivia("What is the best footclub?","Barcalona",10000));
	qs.push_back(trivia("Who is the best football player?","Messi",15000));
	int earned=0;
	cout<<"Trivia Game!!\n";
	for(vector<class trivia>::iterator run=qs.begin();run<qs.end();run++){
		string aanswer;
		cout<<"You have $"<<earned<<"\n";
		cout<<(*run)<<"\n";
		cin>>aanswer;
		if((*run)==aanswer){
			cout<<"That's right! You win  $"<<(*run).returnEarnMoney()<<"\n";
			earned+=(*run).returnEarnMoney();
		}
		else{
			cout<<"Sorry, the correct answer is : "<<(*run).returnTanswer()<<"\n";
		}
	}
	cout<<"Game Over. Your total winnings are $:"<<earned<<"\n";
	return 0;
}
