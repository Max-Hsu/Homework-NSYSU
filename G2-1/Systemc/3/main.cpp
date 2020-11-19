#include "Conv.h"
#include "ROM.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main(int argc,char* argv[])
{
	
	sc_signal<bool> clk,reset;
	sc_signal<bool> rom_rd;
	sc_signal<sc_uint<5> > rom_addr;
	sc_signal<float> data;
	sc_signal<float> result;
	
	
	ROM rom("Rom");
	CONV conv("conv");
	Monitor mon("mon");
	Clock clock("clock",5,200);
	Reset rst("reset",20);
	
	clock(clk);
	rst(reset);
	rom(clk,rom_rd,rom_addr,data);
	conv(clk,reset,data,rom_rd,rom_addr,result);
	mon(clk,result);
	
	
	sc_start(1000,SC_NS);
	return 0;

}











