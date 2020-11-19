#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream Out;
    Out.open("input.txt",fstream::out);
    Out<<"5000000\n";
    for(unsigned int i = 0 ; i < 5000000 ; i++){
        Out<<rand()<<"\n";
    }

}