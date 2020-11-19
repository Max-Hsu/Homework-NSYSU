#include <iostream>
#include <string>
#include "ch7-6.h"
#include <vector>
using namespace std;
pizzaData::pizzaData(string size,string type,int pep,int che):
size(size),type(type),pep(pep),che(che)
{}
void pizzaData::outputDescription(){
	cout<<"This pizza is : "<<size<<", "<<type<<", with "<<pep<<" pepperoni toppings and "<<che<<" cheese toppings.\n";
}
int pizzaData::computePrize(){
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
	return total+2*(pep+che);
}
Order::Order(){}
void Order::order(string size,string type,int pep,int che){
	class pizzaData tempa(size,type,pep,che);
	Data.push_back(tempa);
}
void Order::outputDescription(){
	cout<<"There are "<<Data.size()<<" pizzas in the order.\n";
	for(vector<struct pizzaData>::iterator run=Data.begin();run<Data.end();run++){
		(*run).outputDescription();
	}
}
void Order::computePrize(){
	int total=0;
	for(vector<struct pizzaData>::iterator run=Data.begin();run<Data.end();run++){
		total+=(*run).computePrize();
	}

	cout<<"The total price is $ "<<total<<endl;
}

int main(){
	class Order pizza1;
	pizza1.order("SMALL","HANDTOSSED",0,3);
	pizza1.order("LARGE","PAN",2,1);
	pizza1.outputDescription();
	pizza1.computePrize();
	return 0;
}