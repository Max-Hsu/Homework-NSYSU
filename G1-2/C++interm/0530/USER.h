#include <iostream>
#include <string>
#ifndef USERA
#define USERA
using namespace std;
namespace USER{
class User{
	private:
		string name;
		string passwd;
	public:
		string getusername();
		string getuserpasswd();
		void setusername();
		void setuserpasswd();
};
}
#endif