#include <iostream>
#include <string>
#include "ch10-4.h"

using namespace std;

int main(){
	class subscriber P1;
	P1.set();
	cout<<"Person 1's data:\n";
	P1.output();
	class subscriber P2;
	P2=P1;
	cout<<"Person 2's data after assignment from person 1:\n";
	P2.output();
	P1.reset();
	cout<<"Person 1's data after reset:\n";
	P1.output();
	cout<<"Person 2's data ,should still have original classes:\n";
	P2.output();
	return 0;
}