#include <iostream>
#include "mytar.h"
int main(int argc, char ** argv){
    if (argc < 3 || argv[1][0] != 't')
    {
        std::cerr << "Usage : ./mytar t tarfile \n";
    }
    else{
        if(mytar(argc,argv) == -1){
            std::cerr<<"mytar: "<<argv[2]<<": Cannot open: No such file or directory\nmytar: Error is not recoverable: exiting now\n";
        }
    }
}