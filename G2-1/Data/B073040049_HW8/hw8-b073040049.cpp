/*
Author:許家愷
Date:December.18,2019
Purpose:Huffman compression
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "string.h"
#include <string>
#include <bitset>
#include <cmath>
using namespace std;
unsigned char separate = 10;                        //in other word = next line
struct huff_struct{                                 //this structure is for saving the huffman structure
    huff_struct * left;                             //for the left child
    huff_struct * right;                            //for the right child
    int value;                                      //saving the frequency
    unsigned char worda;                            //the word for encode
};
struct encode{                                      //this is a table for the word to encode
    string code;                                    //the code
    unsigned char the_word;                         //the word
};

bool comp_huff(const huff_struct * a,const huff_struct * b){                        //this bool is used for sorting the huffman elements
    return((a->value<b->value) || ((a->value==b->value)&&a->worda<b->worda));       //return the a verse b frequency if a<b is true vise versa.
}

void travel(huff_struct * X , string outword , vector<encode> &in,unsigned char &code_byte){        //for traveling the huffman tree that has been constructed
                                                                                                    //code_byte is for saving the maximum byte that the code will use
    if(X->left!=nullptr){                                                                           //if there is a left child so travel it
        outword += "0";                                                                             //and the code for next left child is one more '0'
        travel(X->left , outword,in,code_byte);                                                     //travel the left child
        outword.pop_back();                                                                         //with return to the current node the code should delete the last char
    }
    else{
        encode A;                                                                                   //creating the encode table of current node 
        A.code=outword;                                                                             //so code equal code
        A.the_word=X->worda;                                                                        //the_word equal worda
        in.push_back(A);                                                                            //push into the code_table vector
        if(outword.size()>code_byte){                                                               //check if the code needs more byte to save
            //cout<<"change "<<outword.size();
            code_byte = outword.size();
        }
        //cout<<outword<<"\t"<<X->worda<<"\t"<<int(X->worda)<<"\n";
    }
    if(X->right!=nullptr){                                                                          //if there is a right child
        outword += "1";                                                                             //the code for the right child need to append '1' in the last
        travel(X->right , outword,in,code_byte);                                                    //so travel the right child
        outword.pop_back();                                                                         //when return the current node ,it need to delete the last char of code 
    }
}
template<class InputIterator, class T>                                                              //a template for searching the code
InputIterator find_decode (InputIterator first, InputIterator last, const T& val)                   //this is used for decoding the code
{
  while (first!=last) {                                                                             //so iterate all the iterator
    if (((*first).code).compare(val)==0) return first;                                              //if the string match(compare will return 0) , so return that iterator
    ++first;
  }
  return last;
}
template<class InputIterator, class T>                                                              //a template for searching the word
InputIterator find_worda (InputIterator first, InputIterator last, const T& val)                    //this is used for building the huffman tree
{
  while (first!=last) {                                                                             //actually the rest of the searching is identical from the upper code so there will be no comment after
    if ((*first)->worda==val) return first;
    ++first;
  }
  return last;
}
template<class InputIterator, class T>
InputIterator find_encode_worda (InputIterator first, InputIterator last, const T& val)             //find the word relating to code
{
  while (first!=last) {
    if ((*first).the_word==val) return first;
    ++first;
  }
  return last;
}
int error(int x){                                                                                   //error message for safety return 
    string out[] = {"Usage: huffman -c(compress) | -u(uncompress) -i <inputFile> -o <outputFile>\n","somehow error please try again"};
    cout<<out[x];
    return -1;
}
int search_index(char * cpargv[] , char search_word[] , int size){                                  //this function is for argv input and find their index
    for(int i = 0 ; i < size ; i++){                                                                //just simply run through all the element and return
        if(strcmp(cpargv[i],search_word)==0){                                                       //if the two string are the same , it will return 0
            return i;
        }
    }
    return -1;                                                                                      //if find no match , return -1
}
int main(int argc , char * argv[]){
    if(argc<5){                                                                                     //input check if the argument <5 => error
        return error(0);
    }
    if(strcmp(argv[1],"-c")==0){                                                                    //if the command is "-c" for compress
        vector<huff_struct *> sortsa;                                                               //create a vector for saving huff_struct *
        cout<<"compress\n";                                                                         //output compress
        int input_index = search_index(argv,(char *)"-i",argc);                                     //find the right index
        int output_index = search_index(argv,(char *)"-o",argc);                                
        if(abs(input_index-output_index)!=2){                                                       //another check for "-i" "-o" "qwe" "qwe"
            return error(0);                                                                        //like that
        }
        else{                                                                                       //right input
            FILE *in;                                                                               //create FILE for file manipulation
            //FILE *out_code;
            FILE *out;
            unsigned long Size_of_in;                                                               //record the size of the file
            in = fopen(argv[input_index+1],"rb");                                                   //fopen for each file
            out = fopen(argv[output_index+1],"wb");                                             
            //out_code = fopen(code_out_string.c_str(),"wb");
            fseek(in,0,SEEK_END);                                                                   //move the file pointer into the file end
            Size_of_in = ftell(in);                                                                 //return the size of the file
            rewind(in);                                                                             //reset the pointer
            cout<<"Size : "<<Size_of_in<<"\n";                                                      //for output the size of the file
            for(unsigned long a = 0 ; a<Size_of_in ;a++){                                           //this will run through all the byte of the file
                unsigned char c;                                                                    //this will be the char for saving the reading char
                fread(&c,1,1,in);                                                                   //read the file
                vector<huff_struct *>::iterator head = sortsa.begin();                              //iterator for later use
                vector<huff_struct *>::iterator enda = sortsa.end();
                vector<huff_struct *>::iterator result;
                result = find_worda(head,enda,c);                                                   //find the char if the char in the vector
                if(result!=enda){                                                                   //if the char is already in the vector
                    (*result)->value+=1;                                                            //just add the frequency
                }
                else{                                                                               //if there is no char before
                    huff_struct * Temp;                                                             //create a new huff_struct
                    Temp = new huff_struct;
                    Temp->left = nullptr;
                    Temp->right = nullptr;
                    Temp->value = 1;                                                                //frequency is 1
                    Temp->worda = c;                                                                //and the word is char
                    sortsa.push_back(Temp);                                                         //push into the vector
                }
            }
            sort(sortsa.begin(),sortsa.end(),comp_huff);                                            //sort the vector so that the smallest frequency element can go to the front of the stack
            for(vector<huff_struct *>::iterator run = sortsa.begin();run!=sortsa.end();run++){      //for check
                cout<<(*run)->worda<<"\t"<<int((*run)->worda)<<"\t"<<(*run)->value<<"\n";
            }
            while(sortsa.size()>1){                                                                 //this while loop will create the huffman tree by checking the element has left (in the end , there will just a root)
                huff_struct * run;                                                                  //create a new node for combine the two node
                run = new huff_struct;
                run->left = sortsa[0];                                                              //for saving their address (smallest goes to left)
                run->right = sortsa[1];                                                             //and the bigger one goes to the right
                run->value = sortsa[0]->value+sortsa[1]->value;                                     //the frequency is the sum of two node
                run->worda = (sortsa[0]->worda>sortsa[1]->worda)?sortsa[1]->worda:sortsa[0]->worda; //the word is choose with bigger order
                sortsa.erase(sortsa.begin());                                                       //delete the smallest node ,twice
                sortsa.erase(sortsa.begin());
                sortsa.push_back(run);                                                              //push the combined pointer back into the vector for another sort
                sort(sortsa.begin(),sortsa.end(),comp_huff);                                        //do the sort again
            }
            unsigned char code_byte=0;                                                              //for saving the code maximum needed bytes
            vector<encode> table;                                                                   //the code_table
            travel(sortsa[0],"",table,code_byte);                                                   //travel the huffman tree
            
            code_byte = code_byte/8+((code_byte%8)?1:0);                                            //calculate the byte needed
            cout<<"bytes"<<int(code_byte)<<"\n";                                                    //and output for check
            fwrite(&code_byte,1,1,out);                                                             //write it into the output file
            for(vector<encode>::iterator run = table.begin();run != table.end();run++){             //this for loop is for outputing the code_table
                cout<<(*run).code<<"\t"<<(*run).the_word<<"\t"<<int((*run).the_word)<<"\n";         //and stdout for check
                unsigned char the_word = (*run).the_word;                                           //the_word for the_word
                unsigned char code_count;                                                           //code_count means the shift needed to reproduce the code
                unsigned char Bcode;                                                                //Bcode for Binary code
                unsigned char dead_0 = 0;                                                           //dead_0 for unused bit inside one byte
                int counter_for_dump = code_byte;                                                   //counter_for_dump for calculate the byte hasn't done
                string code = (*run).code;                                                          //code for code
                
                code_count = code_byte*8-code.size();                                               //calculate the shift needed
                fwrite(&the_word,1,1,out);                                                          //write the word
                fwrite(&code_count,1,1,out);                                                        //write the shift
                while(code.size()>8){                                                               //when there is not until the last byte
                    bitset<8> strintocode(code.substr(0,8));                                        //using bitset can convert string into char value
                    Bcode = strintocode.to_ulong();                                                 //by using .ulong()                                 
                    code.erase(0,8);                                                                //already produce the number for char , so delete the first 8 element of string
                    fwrite(&Bcode,1,1,out);                                                         //write out the converted Binary code
                    counter_for_dump-=1;                                                            //finish byte -=1
                }
                bitset<8> strintocode(code);                                                        //with last byte
                Bcode = strintocode.to_ulong()<<(code_count%8);                                     //convert it into string and shift if need
                cout<<"Bcode"<<int(Bcode)<<" ";                                                     //for the check
                fwrite(&Bcode,1,1,out);                                                             //write out
                while(counter_for_dump>1){                                                          //if there is an unused byte
                    fwrite(&dead_0,1,1,out);                                                        //padding with 0
                    counter_for_dump-=1;
                }
            }
            fwrite(&separate,1,1,out);                                                              //3 next line symbol for the end of the code_table
            fwrite(&separate,1,1,out);
            fwrite(&separate,1,1,out);
            unsigned int byte_counter_of_tran_word = ((log2(Size_of_in)/8 - int(log2(Size_of_in)/8))>=0)?(int(log2(Size_of_in)/8))+1:int(log2(Size_of_in)/8);       //for saving the size of before encode file
            unsigned char byte_writer = (unsigned char)(byte_counter_of_tran_word);
            fwrite(&byte_writer,1,1,out);                                                           //the first byte indicate how many the byte after will used for indicate the file size

            unsigned long C_Size_of_in = Size_of_in;                                                //process long number
            vector<char> bit_out_as_vector;                                                         //save in vector in order to reverse the order
            while(C_Size_of_in>0){                                                                  //just check the process long number if it is bigger than 0
                unsigned long k = C_Size_of_in>>8;                                                  //by shifting the lowest 8 bit
                k=k<<8;                                                                             //and shift it back
                k=C_Size_of_in-k;                                                                   //after substract the original number , will get the last 8 bit
                C_Size_of_in = C_Size_of_in>>8;                                                     //continue the process
                unsigned char outbit = (unsigned char)k;
                bit_out_as_vector.insert(bit_out_as_vector.begin(),outbit);                         //insert into the string
            }
            for(vector<char>::iterator run = bit_out_as_vector.begin();run!=bit_out_as_vector.end();run++){
                fwrite(&(*run),1,1,out);                                                            //write out the char of number need to process
            }
            //abandoned/
            /*
            while(bit_counter_string.size()>0){
                unsigned char counter;
                bitset<8> counter_bit(bit_counter_string.substr(0,8));
                counter = counter_bit.to_ulong();
                fwrite(&counter,1,1,out_code);
                bit_counter_string.erase(0,8);
            }
            */
            //fclose(out);                                                        //finished code generate
            //next for reading and find out the correct code
            rewind(in);                                                                     //start the conversion

            
            bitset<8> code_bit;                                                             //code_bit will use for string binary code into unsigned char
            string process;                                                                 //encoded string
            for(unsigned long a = 0 ; a<Size_of_in ;a++){                                   //run through the size of the file
                unsigned char c;                                                            //read the char
                fread(&c,1,1,in);
                vector<encode>::iterator head = table.begin();                              //iterator of three for searching word for code
                vector<encode>::iterator enda = table.end();
                vector<encode>::iterator result;
                result = find_encode_worda(head,enda,c);                                    //find the right code
                if(result!=enda){
                    //found the correct
                    process.append((*result).code);                                         //and append into "process"
                }
                else{
                    return error(1);                                                        //if there is no match means unknown error
                }
                while(process.size()>=8){                                                   //if the process.size()>8 means it can produce a byte
                    //cout<<"before"<<process<<"\n";
                    unsigned char code_word;                                                
                    code_bit = bitset<8>(process.substr(0,8));                              //so a new bitset is assign by the front 8 of the process string
                    process.erase(0,8);                                                     //after that erase from the string
                    code_word = code_bit.to_ulong();                                        //convert the bitset into unsigned char
                    //cout<<"after"<<process<<"\n";
                    fwrite(&code_word,1,1,out);                                             //and write out
                }
            }                                                                               //when the code reach here means the conversion is over 
            while (process.size()<8)                                                        //but the last code might not reach 8 bits 
            {
                process += "0";                                                             //so padding the code into a byte
            }
            //cout<<"before"<<process<<"\n";
            unsigned char code_word;                                                        //and convert like upper code
            code_bit = bitset<8>(process.substr(0,8));
            process.erase(0,8);
            code_word = code_bit.to_ulong();
            //cout<<"after"<<process<<"\n";
            fwrite(&code_word,1,1,out);                                                     //write the last byte
            fflush(out);                                                                    //flush
            fclose(out);                                                                    //and save close
        }                                                                           
                                                                                            //the end of compression
    }
    else if(strcmp(argv[1],"-u")==0){                                                       //enter the uncompress
        cout<<"uncompress\n";
        int input_index = search_index(argv,(char *)"-i",argc);                             //search the file index *2
        int output_index = search_index(argv,(char *)"-o",argc);
        if(abs(input_index-output_index)!=2){                                               //if the order of the input index is wrong
            return error(0);                                                                //go to error
        }
        else{
            vector<encode> code_table;                                                      //generate a vector of encode
            FILE *in;                                                                       //FILE operator of in and out
            FILE *out;
            in = fopen(argv[input_index+1],"rb");                                           //open the two file
            out = fopen(argv[output_index+1],"wb");
            //cout<<argv[input_index+1]<<"\t"<<argv[output_index+1]<<"\n";
            unsigned long Size_of_in = 0;
            unsigned char word;
            unsigned char shift;
            unsigned char read_code;
            unsigned char size_of_char;
            unsigned char code_byte;                                                        //first compute the header part
            fread(&code_byte,1,1,in);                                                       //code_byte for the byte size of the code 
            cout<<"code_byte"<<int(code_byte)<<"\n";                                        //output for check
            fread(&word,1,1,in);                                                            //read the first code
            fread(&shift,1,1,in);                                                           //read the first shift
            fread(&read_code,1,1,in);                                                       //read the probably the first of the code
            while(!((word==10)&&(shift==10)&&(read_code==10))){                             //if not reach three line of new lines , (means the header is not finished)
                unsigned char code = read_code;
                bitset<8> bit_code(code);
                struct encode the_code;                                                     //create the structure for encode table 
                the_code.code = bit_code.to_string();                                       //so just convert the first read_code into string like
                for(unsigned char run_byte = 0 ; run_byte < code_byte-1;run_byte++){        //if there is more bytes need for the code
                    fread(&read_code,1,1,in);                                               //read more
                    code =read_code;
                    bit_code = bitset<8>(code);                                             //
                    the_code.code.append(bit_code.to_string());                             //after the conversion , append is the end of the string from the encode structure
                }
                the_code.code.erase(the_code.code.begin()+(8*code_byte-shift),the_code.code.end());         //this is needed because the code has shifted  , so the string need to erase the last element indicated by the shift
                the_code.the_word = word;                                                                   //the word for the word
                code_table.push_back(the_code);                                                             //push the encode_table into vector
                cout<<int(word)<<"\t"<<int(shift)<<"\t"<<the_code.code<<"\n";                               //stdout for check
                fread(&word,1,1,in);                                                        //start reading for next process *3
                fread(&shift,1,1,in);
                fread(&read_code,1,1,in);
            }
            for(vector<encode>::iterator run = code_table.begin();run!=code_table.end();run++){ //output all the encode_table for check
                cout<<(*run).code<<"\t"<<(*run).the_word<<"\n";
            }
            fread(&size_of_char,1,1,in);                                                    //read the char for the following bytes indicating how many word need to be decode
            //cout<<"\n";
            for(unsigned int t = 0;t<size_of_char;t++){                                     
                unsigned char byte_processing;
                fread(&byte_processing,1,1,in);                                             //just read the char
                Size_of_in = (Size_of_in<<8)+(unsigned long)byte_processing;                //and remember to shift and add the char count
                //cout<<Size_of_in<<"\t"<<int(byte_processing)<<"\n";
            }
            cout<<"size:"<<Size_of_in<<"\n";                                                //output the size need to be decode
            unsigned long decode_counter = 0;                                               //for current count of the decoded
            int words_of_string = 1;                                                        //iterate for the size of the code
            string decode_string;                                                           //decode string
            
            while(decode_counter<Size_of_in){                                               //while the decode is not done
                if(words_of_string>decode_string.size()){                                   //the buffer for decode string is not enough
                    fread(&word,1,1,in);                                                    //read the code
                    bitset<8> decode_c(word);                                               //and
                    decode_string += decode_c.to_string();                                  //append into decode_string
                }
                vector<encode>::iterator head = code_table.begin();                         //iterator *3 to find the right coresponding word
                vector<encode>::iterator enda = code_table.end();
                vector<encode>::iterator result;
                result = find_decode(head,enda,decode_string.substr(0,words_of_string));    //find the code
                if(result != enda){                                                         //if found
                    fwrite(&(*result).the_word,1,1,out);                                    //write out the decode word
                    //cout<<(*result).the_word<<"\n";
                    decode_string.erase(decode_string.begin(),decode_string.begin()+words_of_string);       //delete from the decode_string
                    words_of_string = 1;                                                    //reset the words_of_string
                    decode_counter++;                                                       //decode_counter++
                }
                else{
                    words_of_string++;                                                      //if not found the code size pass++
                }
            }
            fclose(in);                                                                     //close the file*2
            fclose(out);                        
        }

    } 
    else{
        return error(0);                                                                    //input error
    }
}
