#include "Lenet.h"
#include <fstream>

void lenet::Neueral(){
    ifstream fin;
    fin.open(INPUT_FILE);
    cout<<"the Input_file is"<<INPUT_FILE<<"\n";
    cout<<"first test the RAM\n";
    if(cycle == 0){
        ram_wr = 1;
        ram_addr = 2;
        ram_data_out = 3;
    }
    else{
        ram_wr = 0;
        ram_addr = 2;
        cout<<ram_data_out;
        sc_stop();
    }
    
    fin.close();
}
