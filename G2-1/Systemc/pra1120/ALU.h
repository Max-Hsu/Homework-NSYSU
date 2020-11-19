#include "systemc.h"

SC_MODULE(ALU)
{	
	sc_in<sc_int<16> > A,B;
	sc_in<sc_uint<3> > opcode;
	sc_out<sc_int<16> > Result;
	sc_out<bool> zero,overflow;
	sc_int<16> a,b,result;
	sc_uint<3> op;

	void alu();
	
	SC_CTOR(ALU)
	{
		SC_METHOD(alu);
		sensitive << A << B << opcode;
	}
};