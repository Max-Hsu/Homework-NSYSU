#include <iostream>
#include <string>
#include "lexer.h"

using namespace std;

int main(int argc , char ** argv){
    if(argc<2){
        cerr<<"./lexer file\n";
        return -1;
    }
    string file_name(argv[1]);
    Lexer Lexer_instance(file_name);
    int file_status = Lexer_instance.file_status();
    while(file_status == 0){
        //cout<<"outer\n";
        Token * X = Lexer_instance.scan();
        if(Lexer_instance.eof_lex_check()){
            break;
        }
        else{
            cout<<"Token: "<<X->toString()<<"\n";
            file_status = Lexer_instance.file_status();
        }
    }
    cout<<"End of file reached\n";
}