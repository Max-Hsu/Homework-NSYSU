#include "pattern.h"

void pattern_gen::pattern(){
	A = rand()%16;
	B = rand()%16;
	/*
	for(int i=0;i<4;i++){
		a[i] = rand()%2;
		b[i] = rand()%2;
	}
	*/
	if(rand()%2){
		for_c = '1';
	}
	else{
		for_c = '0';
	}
	C0 = for_c;
	/*
	A = a;
	B = b;
	*/

	cycle++;
        if(cycle == CYCLE){
        	sc_stop();
	}
}


