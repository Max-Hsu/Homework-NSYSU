#include <iostream>

using namespace std;

int main(){
	int i1=8,i2=10;
	int *p1,*p2;
	p1=&i1;
	p2=&i2;
	
	cout<<"i1:"<<i1<<"\tp1:"<<p1<<"\n";
	cout<<"i2:"<<i2<<"\tp2:"<<p2<<"\n";
	i1=i2;
	cout<<"let i1=i2\n";
	cout<<"i1:"<<i1<<"\tp1:"<<p1<<"\n";
	cout<<"i2:"<<i2<<"\tp2:"<<p2<<"\n";
	p1=p2;
	cout<<"let p1=p2\n";
	cout<<"i1:"<<i1<<"\tp1:"<<p1<<"\n";
	cout<<"i2:"<<i2<<"\tp2:"<<p2<<"\n";
	return 0;
}