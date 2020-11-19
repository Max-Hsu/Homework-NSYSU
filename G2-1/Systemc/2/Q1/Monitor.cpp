#include "Monitor.h"

void Monitor:: monitor(){
	if(counter>2){
		cout<<A<<"\t\t\t"<<B<<"\t\t\t"<<C0<<"\t\t\t"<<S<<"\t\t\t"<<C_out<<"\n";
	}
	else{
		counter++;
	}
}
