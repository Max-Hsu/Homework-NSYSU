#include "systemc.h"
#include <iostream>


using namespace std;

SC_MODULE(ROM)
{	
	sc_in_clk clock;
	sc_in<bool> rom_rd;
	sc_in<sc_uint<5> >rom_addr;
	sc_out<float > data;
	
	float rom_M[110];
	
	void read_data();
	
	SC_CTOR(ROM)
	{
		for(int i=0;i<100;i++){
			rom_M[i] = rand()%256;
		}
		for(int i=100;i<110;i++){
			rom_M[i] = (float)(rand() - (RAND_MAX/2))/ (RAND_MAX + 1.0);;
		}
		SC_METHOD(read_data);
		sensitive << clock.pos();
	}
};


