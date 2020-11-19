#include "ALU.h"
#include "pattern.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main(int argc,char* argv[])
{
	sc_signal<bool> clk,reset,zero,overflow;
	sc_signal<sc_int<16> > A,B,result;
	sc_signal<sc_uint<3> >opcode;
	
	pattern_gen pattern("Generation");
	ALU alu("alu");
	Monitor mon("mon");
	Clock clock("clock",10);
	
	clock(clk);
	pattern(clk,A,B,opcode);
	alu(A,B,opcode,result,zero,overflow);
	mon(clk,result,zero,overflow,A,B,opcode);
	
	
	sc_start(500,SC_NS);
	return 0;

}


