#include "pattern.h"

void pattern_gen::pattern(){
	A = rand()%2;
	B = rand()%2;
	cycle++;
        if(cycle == CYCLE){
                sc_stop();
	}
}


