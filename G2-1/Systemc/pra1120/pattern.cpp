#include "pattern.h"

void pattern_gen::pattern(){

	A = rand()-16324;
	B = rand()-16324;
	opcode = rand()%6;
	
	cycle++;
	if(cycle == CYCLE)
		sc_stop();
}


