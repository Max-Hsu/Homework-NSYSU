#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class file_handler{
    public:
        file_handler(string file_name){
            file.open(file_name,ios_base::in);
            if(!file.is_open()){
                cerr<<"cannot open "<<file_name<<"\n";
            }
        }
        string getline_file(){
            string temp;
            
        }
    private:
        ifstream file;
};
class string_and_token:private file_handler{
    public:
        string_and_token(string file_name):file_handler(file_name){}
        void my_getline(){
            line = file;

        }
    private:
        string line;
};