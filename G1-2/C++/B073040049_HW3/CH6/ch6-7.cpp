#include <iostream>
#include "ch6-7.h"
#include <string>
using namespace std;
pizza::pizza(string size,string type,int pep,int che):
size(size),type(type),pep(pep),che(che){
}
void pizza::outputDescription(){
	cout<<"This pizza is : "<<size<<", "<<type<<", with "<<pep<<" pepperoni toppings and "<<che<<" cheese toppings.\n";
}
void pizza::computePrize(){
	int total=0;
	if(size=="SMALL"){
		total=10;
	}
	else if(size=="MEDIUM"){
		total=14;
	}
	else if(size=="LARGE"){
		total=17;
	}
	cout<<"Prize of pizza : "<<total+2*(pep+che)<<endl;
}
int main(){
	pizza pizza1("SMALL","HANDTOSSED",0,3);
	pizza pizza2("LARGE","PAN",2,1);
	pizza1.outputDescription();
	pizza1.computePrize();
	pizza2.outputDescription();
	pizza2.computePrize();
	return 0;
}