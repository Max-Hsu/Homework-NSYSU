#include "systemc.h"
#include <iostream>
#define CYCLE 10

using namespace std;

SC_MODULE(pattern_gen)
{	
	sc_in_clk clock;
	sc_out<sc_int<16> > A,B;
	sc_out<sc_uint<3> >opcode;
	
	sc_uint<32> cycle;
	
	void pattern();
	
	SC_CTOR(pattern_gen)
	{	
		cycle = 0;
		SC_METHOD(pattern);
		sensitive << clock.neg();
	}
};


