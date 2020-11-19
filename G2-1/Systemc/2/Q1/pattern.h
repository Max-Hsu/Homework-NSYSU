#include "systemc.h"
#include <iostream>
#define CYCLE 10

using namespace std;

SC_MODULE(pattern_gen)
{	
	sc_in_clk clock;
	sc_out<sc_bv<4> > A,B;
	sc_out<sc_bit> C0;
	sc_bit for_c;	
	sc_uint<32> cycle;
	sc_bv<4> a,b;
	
	void pattern();
	
	SC_CTOR(pattern_gen)
	{
		srand(time(NULL));	
		cycle = 0;
		SC_METHOD(pattern);
		sensitive << clock.neg();
	}
};


