#include "systemc.h"

using namespace std;
SC_MODULE(NN)
{	
	public:
		sc_in<float> In1,In2;
		sc_out<float> O;
		SC_HAS_PROCESS(NN);
		NN (sc_module_name  name,int w1 , int w2 , int b):sc_module(name),w1(w1),w2(w2),b(b){
			SC_METHOD(nn_calc);
			sensitive << In1 << In2;
	}

	private:
		int w1 , w2 ,b;
		float O_check;
		void nn_calc();
		
};
