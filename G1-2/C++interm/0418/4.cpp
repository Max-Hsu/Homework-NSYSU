#include <iostream>
#include "3.h"
using namespace std;
void pocket::setMoney(){
	cout<<"How many one-dollar coins ?\n";
	cin>>one;
	cout<<"How many five-dollar coins ?\n";
	cin>>five;
	cout<<"How many ten-dollar coins ?\n";
	cin>>ten;
}
int pocket::OutputA(){
	cout<<"You have : "<<one+five*5+ten*10<<" dollars.\n";
	return one+five*5+ten*10;
}
void pocket::doT(int all){
	int ko,kf,kt;
	for(kt=0;kt<=ten;kt++){
		for(kf=0;kf<=five;kf++){
			for(ko=0;ko<=one;ko++){
				if((kt*10+kf*5+ko)==all){
					ten-=kt;
					five-=kf;
					one-=ko;
					cout<<"Remain ten : "<<ten<<" five : "<<five<<" one : "<<one<<"\n";
					break;
				}
				if((kt*10+kf*5+ko)>all){
					int ak=(kt*10+kf*5+ko)-all;
					ten-=kt;
					five-=kf;
					one-=ko;
					//cout<<" "<<ak;
					ten+=ak/10;
					ak%=10;
					five+=ak/5;
					one+=ak%5;
					//cout<<" "<<kt;
					//cout<<" "<<kf;
					//cout<<" "<<ko;
					
					cout<<"Remain ten : "<<ten<<" five : "<<five<<" one : "<<one<<"\n";
					break;
				}
			}
		}
	}
}
int main(){
	class pocket my;
	my.setMoney();
	my.OutputA();
	cout<<"how much dod you pay by cash ?\n";
	int num;
	cin>>num;
	my.doT(num);
}