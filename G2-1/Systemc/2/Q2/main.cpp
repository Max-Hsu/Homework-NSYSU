#include "NN.h"
#include "pattern.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main(int argc,char* argv[])
{
	sc_signal<bool> clk;
	sc_signal<float> A,B;
	sc_signal<float> w5 , w6 , Y;
	pattern_gen pattern("Generation");
	NN nn_calc1("cal1",10,-10,-5);
	NN nn_calc2("cal2",-10,10,-5);
	NN nn_calc3("cal3",10,10,-5);
	Monitor monitor("mon");
	Clock clock("clock",10);
	
	clock(clk);
	pattern(clk,A,B);
	nn_calc1(A,B,w5);
	nn_calc2(A,B,w6);
	nn_calc3(w5,w6,Y);
	monitor(clk,A,B,Y);

	
	sc_start(500,SC_NS);
	return 0;

}


