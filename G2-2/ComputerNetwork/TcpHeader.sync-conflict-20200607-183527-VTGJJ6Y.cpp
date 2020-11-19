#include <stdio.h>
#include <iostream>
#include <bitset>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "TcpHeader.hpp"

template <class T>
void charToType(T & dest,const char * ptrOfChar,size_t sizeOfBytes){ //only can process more than 8 bits!!

    std::bitset<8*sizeof(T)> tmpOfWhole;
    for(int i = 0 ; i < sizeof(T) ; i++){
        std::bitset<8> tmpOfByte(ptrOfChar[i]);
        for(int j=7 ; j>=0 ;j--){
            tmpOfWhole[8*(sizeof(T)-1-i)+j] = tmpOfByte[j];
        }
    }
    //std::cout<<tmpOfWhole.to_string()<<"\n";
    dest = tmpOfWhole.to_ullong();
}

template <class T>
void charToBit(T & dest, const char * ptrOfChar,size_t offset){ //count from right
    std::bitset <8> tmp(ptrOfChar[0]);
    dest = tmp[offset];
}

void charToTcp(struct TcpHEADER & header , char * ptrOfChar){ //this will not process the "options"
    charToType  (header.Source_Port         , ptrOfChar     ,2);
    charToType  (header.Destination_Port    , ptrOfChar+2   ,2);
    charToType  (header.Sequence_Number     , ptrOfChar+4   ,4);
    charToType  (header.Ack_Number          , ptrOfChar+8   ,4);
    charToType  (header.Data_Offset         , ptrOfChar+12  ,1);
    header.Data_Offset >>= 4;
    header.Data_Offset <<= 2;
    charToBit   (header.NS                  , ptrOfChar+12  ,0);
    charToBit   (header.CWR                 , ptrOfChar+13  ,7);
    charToBit   (header.ECE                 , ptrOfChar+13  ,6);
    charToBit   (header.URG                 , ptrOfChar+13  ,5);
    charToBit   (header.ACK                 , ptrOfChar+13  ,4);
    charToBit   (header.PSH                 , ptrOfChar+13  ,3);
    charToBit   (header.RST                 , ptrOfChar+13  ,2);
    charToBit   (header.SYN                 , ptrOfChar+13  ,1);
    charToBit   (header.FIN                 , ptrOfChar+13  ,0);
    charToType  (header.Window_Size         , ptrOfChar+14  ,2);
    charToType  (header.CheckSum            , ptrOfChar+16  ,2);
    charToType  (header.Urgent_Pointer      , ptrOfChar+18  ,2);
}
int findArgument(const char * finding ,char ** theWholeArgument , const int argc){ // this will return the index after the "-option" 
    for(int i = 0 ; i< argc ; i++){
        if(strcmp(theWholeArgument[i],finding)==0 && i+1<argc){
            return i+1;
        }
    }
    return -1;
}

template <class T>
void typeToChar(const T & data, char * destptrOfChar){
    std::bitset<sizeof(T)*8> tmpOfWhole (data);
    for(int i=sizeof(T)-1;i>=0;i--){
        std::bitset<8> tmpOfByte;
        for(int j=7;j>=0;j--){
            tmpOfByte[j] = tmpOfWhole[i*8+j];
            //std::cout<<tmpOfByte[j];
        }
        destptrOfChar[(sizeof(T)-1-i)] = tmpOfByte.to_ulong();
    }
    //std::cout<<"\n";
}

template <class T>
void bitToChar(const T & data, char * ptrOfChar,size_t offset){
    std::bitset<8> Tmp(ptrOfChar[0]);
    Tmp[offset] = data;
    ptrOfChar[0] = Tmp.to_ulong();
}

void makePacket(const struct TcpHEADER Header , char * packetChar , size_t size){
    typeToChar  (Header.Source_Port         , packetChar         );
    typeToChar  (Header.Destination_Port    , packetChar+2       );
    typeToChar  (Header.Sequence_Number     , packetChar+4       );
    typeToChar  (Header.Ack_Number          , packetChar+8       );
    unsigned char tmp_Data_Offset = Header.Data_Offset;
    tmp_Data_Offset <<= 2;
    typeToChar  (tmp_Data_Offset            , packetChar+12      );
    bitToChar   (Header.NS                  , packetChar+12  ,0  );
    bitToChar   (Header.CWR                 , packetChar+13  ,7  );
    bitToChar   (Header.ECE                 , packetChar+13  ,6  );
    bitToChar   (Header.URG                 , packetChar+13  ,5  );
    bitToChar   (Header.ACK                 , packetChar+13  ,4  );
    bitToChar   (Header.PSH                 , packetChar+13  ,3  );
    bitToChar   (Header.RST                 , packetChar+13  ,2  );
    bitToChar   (Header.SYN                 , packetChar+13  ,1  );
    bitToChar   (Header.FIN                 , packetChar+13  ,0  );
    typeToChar  (Header.Window_Size         , packetChar+14      );
    typeToChar  (Header.CheckSum            , packetChar+16      );
    typeToChar  (Header.Urgent_Pointer      , packetChar+18      );
}

void displayPacket(const struct TcpHEADER Header){
    printf("%16ld%16ld\n",Header.Source_Port,Header.Destination_Port);
    printf("%32ld\n",Header.Sequence_Number);
    printf("%32ld\n",Header.Ack_Number);
    printf("%4d%d%d%d%d%d%d%d%d%d%d%d%d%16ld\n",Header.Data_Offset,0,0,0,Header.NS,Header.CWR,Header.ECE,Header.URG,Header.ACK,Header.PSH,Header.RST,Header.SYN,Header.FIN,Header.Window_Size);
    printf("%16ld%16ld\n",Header.CheckSum,Header.Urgent_Pointer);
}