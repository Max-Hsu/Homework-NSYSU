#include "systemc.h"
#include <iostream>
#define CYCLE 10

using namespace std;

SC_MODULE(pattern_gen)
{	
	sc_in_clk clock;
	sc_out<float> A,B;
	sc_uint<32> cycle;
	void pattern();
	
	SC_CTOR(pattern_gen)
	{
		srand(time(NULL));	
		cycle = 0;
		SC_METHOD(pattern);
		sensitive << clock.neg();
	}
};


