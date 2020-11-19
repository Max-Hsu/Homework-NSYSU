#include "full_adder.h"


void FULL::full_adder()
{
	c = C0;
	tr_a = A.read();
	tr_b = B.read();
	for(int i = 0 ; i < 4;i++){
		a = tr_a[i];
		b = tr_b[i];
		xor1 = a ^ b;
		and1 = a & b;
		s = xor1 ^ c;
		and2 = xor1 & c;
		c = and1 | and2;
		S_temp[i] = s;
	}
	S = S_temp;
	C_out = c;
}
