/*
Author:許家愷
Date:September.10,2019
Purpose:printing factorial
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int calc_precision(int ii,int per){                                                                 //this function return the number of the place where 'per' assigned
    char ii_char[20];                                                                               //i can convert 20 digits at most
    sprintf(ii_char,"%20d",ii);                                                                     //int to char array
    return int(ii_char[19-per])-48;                                                                 //return the number
}
int main(){
    int inputa;
    while(true){                                                                                    //keep running until the input < 1
        cin>>inputa;
        if(inputa<1){                                                                               //checking the number
            break;
        }
        cout<<"1!=1\n";
        vector <int> numwq(1,1);                                                                    //starting the number array with 1
        int in = -1;
        for(int i=2 ; i<=inputa ; i++){                                                             //run the numbers which user assigned
            int log_of_i=-1;

            for(int run = 1 ; run<=10000 ; run*=10){                                                //this also check the current multiply numbers size
                if(i/run>=1){
                    log_of_i++;
                }
                else{
                    break;
                }
            }

            vector<vector<int>> adder;
            for(int run = 0 ; run<=log_of_i ; run++){
                int multiply= calc_precision(i,run);                                                //multiply every 'run' number
                vector<int>line(run,0);                                                             //so each of multiplaction create their own line 

                vector<int>::iterator line_runner=line.begin();
                for(vector<int>::iterator it = numwq.end()-1;it>=numwq.begin();it--){               //this will multiply all the number of multiplaction before
                    line.insert(line_runner,(*it)*multiply);                                        //insert it from right to left one by one
                    line_runner = line.begin();
                    if(in!=-1){
                        (*line_runner)+=in;
                        //cout<<(*line_runner)<<"line_runner\n";
                        in=-1;
                    }
                    if((*line_runner)>=10){                                                         //if the multiplaction result is >10 then carry to next digit
                        in = (*line_runner)/10;
                        //cout<<i<<" "<<in<<"\n";
                        (*line_runner)%=10;
                    }
                    else {
                        in = -1;
                    }
                }
                if(in!=-1){
                    line.insert(line.begin(),in);                                                   //if the digit is the leftest one, it need to carry to a new digit, so there is a insert
                    in=-1;
                }
                adder.push_back(line);                                                              //and this multiplaction line will store in a bigger array 'adder'
            }
            vector<int> adding;                                                                     //after multiply all digits we need them to sum up
            vector<int>::iterator adding_run=adding.begin();
            int runner=0;
            int in2=0;
            for(runner = 0; runner <(*(adder.end()-1)).size();runner++){                            //this will run through all the line multiply before
                for(vector<vector<int>>::iterator rinaa = adder.begin();rinaa<adder.end();rinaa++){ //and this get the specfied position of the line
                    vector<int>::iterator rinaa_run=(*rinaa).end()-1-runner;
                    if(rinaa_run>=(*rinaa).begin()&&rinaa_run<(*rinaa).end()){
                        if(adding.size()==runner){
                                adding.insert(adding.begin(),0);                                    //adding all the numbers that every lines current digits
                        }
                        adding_run=adding.begin();
                        (*adding_run)+=(*rinaa_run);
                        //cout<<runner<<" at "<<*adding_run<<"\n";
                    }
                    //cout<<"\n";
                }
            }
            for(adding_run=adding.end()-1;adding_run>=adding.begin();adding_run--){
                if(in2>0){
                    //cout<<"new in2 for "<<in2 <<"\n";
                    (*adding_run)+=in2%10;                                                          //checking after adding's digit whether it >10
                    in2/=10;
                }
                if(*adding_run>=10){                                                                //if true then carry
                    //cout<<*adding_run<<" as now \n";
                    in2 += (*adding_run)/10;
                    (*adding_run)%=10;
                }
                if(in2>0&&adding_run == adding.begin()){                                            //if it reach the leftest digit and still need to be carry
                    adding.insert(adding.begin(),in2%10);                                           //so insert a new place
                    in2/=10;
                    adding_run = adding.begin();
                }
            }
            numwq = adding;
            cout<<i<<"!=";
            for(vector<int>::iterator run_adding = adding.begin();run_adding<adding.end();run_adding++){
                cout<<*run_adding;                                                                  //run through and display all the digits
            }
            cout<<"\n";
        }
        cout<<"\n";

    }
}
