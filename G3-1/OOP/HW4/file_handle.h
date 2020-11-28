#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class file_handler{
    public:
        file_handler(){}
        file_handler(string file_name){
            file.open(file_name,ios_base::in);
            if(!file.is_open()){
                cerr<<"cannot open "<<file_name<<"\n";
            }
        }
        int open(string file_name){
            file.open(file_name,ios_base::in);
            if(!file.is_open()){
                cerr<<"cannot open "<<file_name<<"\n";
            }
        }
        char char_get(int & status){
            char temp;
            file.get(temp);
            if(file.eof()){
                status = -1;
            }
            else{
                status = 0;
            }
            return temp;
        }
        char char_peek(int & status){
            char temp;
            temp = file.peek();
            if(file.eof()){
                status = -1;
            }
            else{
                status = 0;
            }
            return temp;
        }
    private:
        ifstream file;
};
