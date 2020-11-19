#include <iostream>
#include <string>
using namespace std;
class User{
	private:
		string name;
		string passwd;
	public:
		string getusername(){
			return this->name;
		}
		string getuserpasswd(){
			return this->passwd;
		}
		void setusername(){
			string name;
			cout<<"Please input your name\n";
			cin>>name;
			while(name.size()<5){
				cout<<"Please input your name again...\n";
				cin>>name;
			}
			this->name=name;
		}
		void setuserpasswd(){
			string passwd;
			cout<<"Please input your passwd\n";
			cin>>passwd;
			while(passwd.size()<5){
				cout<<"Please input your passwd again...\n";
				cin>>passwd;
			}
			this->passwd=passwd;
		}
};

int main(){
	class User A;
	A.setusername();
	A.setuserpasswd();
	cout<<"Your account is "<<A.getusername()<<"\nYour passwd is "<<A.getuserpasswd()<<"\n";
	return 0;
}