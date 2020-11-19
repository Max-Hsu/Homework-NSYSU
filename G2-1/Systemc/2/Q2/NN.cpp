#include "NN.h"

void NN::nn_calc()
{
	float x = In1*w1+In2*w2+b;
	O_check = 0.5+0.25*x-x*x*x/48+x*x*x*x*x/480;

	if(O_check>1){
		O = 1;
	}
	else if(O_check<0){
		O = 0;
	}
	else{
		O = O_check;
	}
	//cout<<"\n"<<In1<<"\t"<<In2<<"\t"<<w1<<"\t"<<w2<<"\t"<<b<<"\t"<<O_check<<"\t"<<O<<"\n";
	//cout<<O_check<<"\t"<<O<<"\n";

}
