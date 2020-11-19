#include "Monitor.h"

void Monitor:: monitor(){
	op = opcode;
	a = A;
	b = B;
	r = result;
	if(op == 0 || op == 1 || op == 5){
		
		for(int i=0;i<16;i++){
			cout<<a[i];
		}
		cout<<"\t\t\t";
		for(int i=0;i<16;i++){
			cout<<b[i];
		}
		cout<<"\t\t\t";
		cout<<op;
		cout<<"\t\t\t";
		for(int i=0;i<16;i++){
			cout<<r[i];
		}
		cout<<"\t\t\t";
		cout<<zero<<"\n";
		
	}
	else{
		cout<<a<<"\t\t\t\t\t"<<b<<"\t\t\t\t\t"<<op<<"\t\t\t\t"<<r<<"\t\t\t\t"<<zero<<"\n";
	}
	
}
