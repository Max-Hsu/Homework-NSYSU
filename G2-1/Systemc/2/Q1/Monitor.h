#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE(Monitor)
{	
	sc_in_clk clock;
	sc_in<sc_bv<4> > A,B,S;
	sc_in<sc_bit> C0;
	sc_in<sc_bit> C_out;
	int counter;
	void monitor();
	
	SC_CTOR(Monitor)
	{	
		counter = 0;
		cout<<"A\t\t\tB\t\t\tC0\t\t\tS\t\t\tC_out\n";
		SC_METHOD(monitor);
		sensitive << clock.pos();
	}
};

