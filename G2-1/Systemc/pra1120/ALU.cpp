#include "ALU.h"


void ALU::alu()
{
	a = A;
	b = B;
	result = Result;
	op = opcode;
	switch(op){
		case 0:
			result = a & b;
			break;
		case 1:
			result = a | b;
			break;
		case 2:
			result = a + b;
			if(a>0 && b>0 && result<0){
				overflow = 1;
			}
			if(a<0 && b<0 && result>0){
				overflow = 1;
			}
			if(result == 0){
				zero = 1;
			}
			break;
		case 3:
			result = a - b;
			if(result == 0){
				zero = 1;
			}
			break;
		case 4:
			if(a<b){
				result = 1;
			}
			else{
				result = 0;
			}
			break;
		case 5:
			result = ~(a | b);
			break;
	}
	Result = result;
}
