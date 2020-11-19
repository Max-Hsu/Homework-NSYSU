#include "Monitor.h"


void Monitor:: monitor(){
	if(counter%8 == 0){
		cout<<"\n";
	}
	cout << result <<"\t"<< endl;

	counter++;
}


