#include <iostream>
#include <string>
#include "USER.h"

using namespace std;

namespace USER{
	string User::getusername(){
			return this->name;
	}
	string User::getuserpasswd(){
			return this->passwd;
	}
	void User::setusername(){
			string name;
			cout<<"Please input your name\n";
			cin>>name;
			while(name.size()<5){
				cout<<"Please input your name again...\n";
				cin>>name;
			}
			this->name=name;
	}
	void User::setuserpasswd(){
			string passwd;
			cout<<"Please input your passwd\n";
			cin>>passwd;
			while(passwd.size()<5){
				cout<<"Please input your passwd again...\n";
				cin>>passwd;
			}
			this->passwd=passwd;
	}
}