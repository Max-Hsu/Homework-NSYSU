#include "systemc.h"
#include "run_mode.h"
#include<iostream>
#include<fstream>



using namespace std;

SC_MODULE(lenet)
{	
	sc_in_clk clock;
	sc_in<bool> reset;
	sc_out<bool> rom_rd;
	sc_out<bool> ram_wr;
	sc_out<sc_uint<16> > rom_addr;
	sc_out<sc_uint<16> > ram_addr;
	sc_in<TYPE > rom_data_in;
	sc_in<TYPE > ram_data_in;
	sc_out<TYPE > ram_data_out;
	sc_out<TYPE > result;
	sc_out<bool> valid;
	int cycle;
	void Neural();
	

	
	SC_CTOR(lenet)
	{
		cycle = 0;
		fin.open(INPUT_FILE);
		SC_METHOD(Neural);
		sensitive << clock.neg();
	}
};

