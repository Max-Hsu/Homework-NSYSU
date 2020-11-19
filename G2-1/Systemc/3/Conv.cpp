#include "Conv.h"

void CONV::conv(){
	if(cycle>111 &&cycle<176){
		int process = (cycle-112)+(cycle-112)/8*10;
		Result = value[process]*value[100]+value[process+1]*value[101]+value[process+2]*value[102]+value[process+10]*value[103]+value[process+11]*value[104]+value[process+12]*value[105]+value[process+20]*value[106]+value[process+21]*value[107]+value[process+22]*value[108]+value[109];
		//cout<<"c"<<cycle<<Result<<"\n";
	}
	else{
		if(cycle>=0){
			rom_rd.write(1);
			rom_addr.write(cycle);
		}
		if(cycle>0){
			value[cycle-1] = data.read();
		}
	}
	cycle++;

	
}


