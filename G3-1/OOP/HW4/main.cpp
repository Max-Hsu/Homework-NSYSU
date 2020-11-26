#include <iostream>
#include <string>
#include "file_handle.h"


int main(int argc , char ** argv){
    if(argc<2){
        std::cerr<<"./lexer file\n";
    }
    int status;
    file_handler hi("file");
    std::cout<<status<<hi.char_get(status)<<"\n";
    std::cout<<status<<hi.char_get(status)<<"\n";
    std::cout<<status<<hi.char_get(status)<<"\n";
    std::cout<<status<<hi.char_get(status)<<"\n";
    std::cout<<status<<hi.char_get(status)<<"\n";
    std::cout<<status<<hi.char_get(status)<<"\n";

}