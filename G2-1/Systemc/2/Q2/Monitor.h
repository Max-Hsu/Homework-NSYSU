#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE(Monitor)
{	
	sc_in_clk clock;
	sc_in<float> A,B,Y;
	void monitor();
	int counter;	
	SC_CTOR(Monitor)
	{	
		cout<<"A\t\t\tB\t\t\tY\n";
		counter = 0;
		SC_METHOD(monitor);
		sensitive << clock.pos();
	}
};

