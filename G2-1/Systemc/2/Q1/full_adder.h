#include "systemc.h"

using namespace std;
SC_MODULE(FULL)
{	
	sc_in<sc_bv<4> > A,B;
	sc_in<sc_bit> C0;
	sc_out<sc_bv<4> > S;
	sc_out<sc_bit> C_out;
	
	sc_bv<4> tr_a,tr_b;
	sc_bit a,b,s,c;
	sc_bit xor1,xor2,and1,and2,or1;
	sc_bv<4> S_temp;	
	void full_adder();
	
	SC_CTOR(FULL)
	{
		SC_METHOD(full_adder);
		sensitive << A << B << C0;
	}
};
