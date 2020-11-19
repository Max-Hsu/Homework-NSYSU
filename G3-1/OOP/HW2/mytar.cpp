#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include "mytar.h"
using std::ifstream;
uint64_t octal_To_Decimal(char * the_string , int size){
    size-=1;
    uint64_t num = (the_string[size-1] - '0');
    for(int i=size-2 ; i >= 0 ;i-=1){
        num += (the_string[i] - '0') * (8<<(3*(size - i -2)));
    }
    return num;
}

uint16_t calc_checksum(char * read_buf,int size , int offset_checksum){
    uint16_t adder = 0;
    for (int i =0 ; i< size ;i+=1){
        if(i == offset_checksum){
            i+= 8;
        }
        adder +=read_buf[i];
    }
    
    //std::cout<<adder<<"\n";
    return adder;
}
void getmode(char * the_string , int size){
    for(int i = 4 ; i<=6 ; i++){
        int mode_value = the_string[i] - '0';
        if(mode_value & 4){
            std::cout<<'r';
        }
        else{
            std::cout<<'-';
        }
        if(mode_value & 2){
            std::cout<<'w';
        }
        else{
            std::cout<<'-';
        }
        if(mode_value & 1){
            std::cout<<'x';
        }
        else{
            std::cout<<'-';
        }
    }
}
int mytar(int argc ,char ** argv){
    ifstream file;
    file.open(argv[2],std::ios_base::in);
    char end_of_file [1024] = {0};
    if(file.good()){ //the file is present
        char read_buf[WITH_USTAR_SIZE];
        struct with_ustar_header * ustar_header;
        ustar_header = (struct with_ustar_header *)malloc(WITH_USTAR_SIZE);
        struct without_ustar_header * not_ustar_header;
        not_ustar_header = (struct without_ustar_header *)malloc(WITHOUT_USTAR_SIZE);
        //what to do if the file is smaller than WITH_USTAR_SIZE
        file.seekg(0,std::ios_base::end);
        size_t tar_size = file.tellg();
        file.seekg(0);
        size_t current_pointer = 0;
        while(current_pointer <= tar_size){
            //!!!should we perform checksum?
            file.seekg(current_pointer);
            file.read(read_buf,WITH_USTAR_SIZE);
            //do ustar check to make sure it is tar file
            memcpy(ustar_header,read_buf,WITH_USTAR_SIZE);
            //std::cout<<ustar_header->magic;
            //strncmp("ustar\0",ustar_header->magic,sizeof(ustar_header->magic)
            if(strncmp("ustar",ustar_header->magic,5) == 0){ // yes it is tar format
                //std::cout<<"hi\n";
                //std::cout<<ustar_header->chksum<<"\n";
                //std::cout<<octal_To_Decimal(ustar_header->chksum,7) <<" "<<calc_checksum(read_buf,WITH_USTAR_SIZE,148)<<"\n";
                if(octal_To_Decimal(ustar_header->chksum,7)-256 == calc_checksum(read_buf,WITH_USTAR_SIZE,148)){
                    char time_output_buf[80];
                    time_t filetime(octal_To_Decimal(ustar_header->mtime,12));
                    struct tm conversion_to_readable;
                    conversion_to_readable = *localtime(&filetime);
                    strftime(time_output_buf, sizeof(time_output_buf), "%Y-%m-%d %H:%M", &conversion_to_readable);
                    //std::cout<<time_output_buf<<"\n";
                    
                    switch( ustar_header->typeflag ){
                        case '0':
                        case '\0':
                            //Normal file
                            std::cout<<"-";
                            break;
                        case '1':
                            //Hard link
                            std::cout<<"h";
                            break;
                        case '2':
                            //symbolic link
                            std::cout<<"l";
                            break;
                        case '3':
                            //Character Special
                            std::cout<<"c";
                            break;
                        case '4':
                            //Block special
                            std::cout<<"b";
                            break;
                        case '5':
                            //Dir
                            std::cout<<"d";
                            break;
                        case '6':
                            //FIFO
                            break;
                        case '7':
                            //Contiguous file
                            break;
                        case 'g':
                            //Global extended header POSIX.1-2001
                            break;
                        case 'x':
                            //Extended header
                            break;
                    }
                    
                    getmode(ustar_header->mode,sizeof(ustar_header->mode));

                    std::cout<<"\t"<<ustar_header->uname<<"/"<<ustar_header->gname<<"\t";
                    std::cout.width(10);
                    std::cout<<octal_To_Decimal(ustar_header->size,12);
                    std::cout<<"\t"<<time_output_buf<<"\t";
                    std::cout<<ustar_header->name<<"\n";

                    current_pointer += octal_To_Decimal(ustar_header->size,12) + 512;
                    if(octal_To_Decimal(ustar_header->size,12) >0){
                        current_pointer += (512 - (current_pointer%512));
                    }
                }
                else{
                    std::cerr<<"file corrupted , please check\n";
                }
            }
            else{ //no it doesn't have ustar format , but it still can apply without_ustar_header , or otherwise it might be the end of file check
                char test_end_of_file [1024] = {0};
                file.seekg(current_pointer);
                file.read(read_buf,WITHOUT_USTAR_SIZE); // so we first check not ustar format
                if(file.eof() || file.bad()){
                    //std::cout<<"no please\n";
                    return -1;
                }
                else{
                    memcpy(not_ustar_header,read_buf,WITHOUT_USTAR_SIZE);
                    if(octal_To_Decimal(not_ustar_header->chksum,7)-256 == calc_checksum(read_buf,WITH_USTAR_SIZE,148)){ // if the checksum is ok
                        char time_output_buf[80];
                        time_t filetime(octal_To_Decimal(not_ustar_header->mtime,12));
                        struct tm conversion_to_readable;
                        conversion_to_readable = *localtime(&filetime);
                        strftime(time_output_buf, sizeof(time_output_buf), "%Y-%m-%d %H:%M", &conversion_to_readable);
                        //std::cout<<time_output_buf<<"\n";
                        
                        switch( not_ustar_header->typeflag ){
                            case '0':
                            case '\0':
                                //Normal file
                                std::cout<<"-";
                                break;
                            case '1':
                                //Hard link
                                std::cout<<"h";
                                break;
                            case '2':
                                //symbolic link
                                std::cout<<"l";
                                break;
                        }
                        
                        getmode(not_ustar_header->mode,sizeof(not_ustar_header->mode));

                        std::cout<<"\t"<<not_ustar_header->uid<<"/"<<not_ustar_header->gid<<"\t";
                        std::cout.width(10);
                        std::cout<<octal_To_Decimal(not_ustar_header->size,12);
                        std::cout<<"\t"<<time_output_buf<<"\t";
                        std::cout<<not_ustar_header->name<<"\n";

                        current_pointer += octal_To_Decimal(not_ustar_header->size,12) + 512;

                        if(octal_To_Decimal(ustar_header->size,12) >0){
                            current_pointer += (512 - (current_pointer%512));
                        }
                    }
                    else{   // it even fails with without tar format check , the only possible explanation is the end of file
                        file.seekg(current_pointer);
                        file.read(test_end_of_file,sizeof(test_end_of_file));
                        if(file.eof() || file.bad()){ // i am out of excuses we just couldn't read
                            //std::cout<<"no please\n";
                            return -1;
                        }
                        if(memcmp(test_end_of_file,end_of_file,sizeof(test_end_of_file))==0){ //end of file
                            return 0;
                        }
                    }       
                }

                //not ustar format !!! or not tar file //can be judge by checksum...
                
                //lets test with not ustar format first
            }
        }
        free(ustar_header);
        free(not_ustar_header);
    }
    else{
        std::cerr<<"cannot find file\n";
    }
    return -1;
}