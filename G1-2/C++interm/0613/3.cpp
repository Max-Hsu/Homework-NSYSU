#include <iostream>
#include <string>

using namespace std;

class detail{
	public:
		detail(string namea,int atka,int HPa,string attra):name(namea),atk(atka),HP(HPa),attr(attra){}
		void out(){
			cout<<name<<" Type : "<<attr<<" atk : "<<atk<<" HP : "<<HP<<"\n";
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

int main(){
	fire A("Charmander",3,10);A.out();
	fire B("Charmeleon",7,20);B.out();
	fire C("Charizard",15,40);C.out();
	water D("Squirtle",3,40);D.out();
	water E("Wartortle",7,20);E.out();
	water F("Blastoise",15,40);F.out();
	grass G("Bulbasaur",3,10);G.out();
	grass H("Ivysaur",7,20);H.out();
	grass I("Venusaur",15,40);I.out();
	

}