#include <iostream>
#include <string>
#include <vector>
using namespace std;

class detail{
	public:
		detail(){}
		detail(string namea,int atka,int HPa,string attra):name(namea),atk(atka),HP(HPa),attr(attra){}
		void setall(string namea,int atka,int HPa,string attra){
			
			this->name=namea;
			this->atk=atka;
			this->HP=HPa;
			this->attr=attra;
		}
		int getHP(){
			return this->HP;
		}
		int minusHP(int minus){
			this->HP=this->HP-minus;
			return this->HP;
		}
		string getattr(){
			return this->attr;
		}
		int getatk(){
			return this->atk;
		}
		void out(){
			cout<<name<<" Type : "<<attr<<" atk : "<<atk<<" HP : "<<HP<<"\n";
		}
		string getname(){
			return this->name;
		}
	protected:
		string name;
		int atk;
		int HP;
		string attr;
};
class fire:public detail{
	public:
		fire(string namea,int atka,int HPa):detail(namea,atka,HPa,"fire"){}
	
	
};
class water:public detail{
	public:
		water(string namea,int atka,int HPa):detail(namea,atka,HPa,"water"){}
	
	
};
class grass:public detail{
	public:
		grass(string namea,int atka,int HPa):detail(namea,atka,HPa,"grass"){}
};
class POKE:public detail{
	public:
		POKE(string namea,int atka,int HPa,string attra){
			if (attra == "fire"){
				setall(namea,atka,HPa,attra);
			}
			else if(attra == "water"){
				setall(namea,atka,HPa,attra);
			}
			else if(attra == "grass"){
				setall(namea,atka,HPa,attra);
			}
		}
		int fight(POKE& B){
			cout<<" "<<getname()<<" atk "<<B.getname()<<"\n";
			if(getattr()=="water" && B.getattr()=="fire"){
				B.minusHP(getatk()*2);
				return B.getHP();
			}
			else if(getattr()=="fire" && B.getattr()=="grass"){
				B.minusHP(getatk()*2);
				return B.getHP();
			}
			else if(getattr()=="grass" && B.getattr()=="water"){
				B.minusHP(getatk()*2);
				return B.getHP();
			}
			else{
				B.minusHP(getatk());
				return B.getHP();
			}
		}
};
int main(){
	vector<class POKE>list;
	list.push_back(POKE("Charmander",3,10,"fire"));
	list.push_back(POKE("Charmeleon",7,20,"fire"));
	list.push_back(POKE("Charizard",15,40,"fire"));
	list.push_back(POKE("Squirtle",3,40,"water"));
	list.push_back(POKE("Wartortle",7,20,"water"));
	list.push_back(POKE("Blastoise",15,40,"water"));
	list.push_back(POKE("Bulbasaur",3,10,"grass"));
	list.push_back(POKE("Ivysaur",7,20,"grass"));
	list.push_back(POKE("Venusaur",15,40,"grass"));
	for(int i=0;i<9;i++){
		list[i].out();
	}
	int x,y;
	cin>>x>>y;
	
	while(true){
		int left=list[x].fight(list[y]);
		cout<<"left blood "<<left<<" \n";
		if(left<0){cout<<"dead\n";break;}
		left=list[y].fight(list[x]);
		cout<<"left blood "<<left<<" \n";
		if(left<0){cout<<"dead\n";break;}
	}

}