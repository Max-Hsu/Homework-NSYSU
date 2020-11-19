#include <iostream>
#include <string>
#include "USER.h"
using namespace std;


int main(){
	//using USER::User;
	class USER::User A;
	A.setusername();
	A.setuserpasswd();
	cout<<"Your account is "<<A.getusername()<<"\nYour passwd is "<<A.getuserpasswd()<<"\n";
	return 0;
}