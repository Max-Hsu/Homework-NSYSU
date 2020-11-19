#include "systemc.h"

SC_MODULE(CONV)
{	
	sc_in_clk clk;
	sc_in<bool>reset;
	sc_in<float> data;
	sc_out<bool>rom_rd;
	sc_out<sc_uint<5> >rom_addr;
	sc_out<float> Result;
	int cycle;
	float value[150];
	
	void conv();
	
	SC_CTOR(CONV)
	{	
		cycle = -2;
		SC_METHOD(conv);
		sensitive << clk.neg();
	}
};





