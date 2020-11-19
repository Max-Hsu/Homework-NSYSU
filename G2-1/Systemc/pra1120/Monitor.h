#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE(Monitor)
{	
	sc_in_clk clock;
	sc_in<sc_int<16> >result;
	sc_in<bool> zero,overflow;
	sc_in<sc_int<16> > A,B;
	sc_in<sc_uint<3> >opcode;
	
	sc_uint<3> op;
	sc_int<16>a,b,r;
	void monitor();
	
	SC_CTOR(Monitor)
	{	

		SC_METHOD(monitor);
		sensitive << clock.pos();
	}
};

