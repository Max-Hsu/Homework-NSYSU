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
using namespace std;

int main(int argc , char ** argv){
    srand(time(NULL));
    int index_IP;
    int index_Port;
    int index_Option;
    int index_File;
    int socketFd;
    uint32_t server_s_sequence_number;
    uint16_t My_Source_Port = rand()%65536;
    uint32_t My_Sequence_Number = (rand()%10000)+1;
    char ReceivingBUF[UDP_MAX];
    index_IP    =   findArgument("-i",argv,argc);
    index_Port  =   findArgument("-o",argv,argc);
    index_Option=   findArgument("-s",argv,argc);
    index_File  =   findArgument("-f",argv,argc);

    struct sockaddr_in client;
    struct sockaddr_in server;
    memset(&client,'\0',sizeof(client));
    memset(&server,'\0',sizeof(server));

    if(argc<5 || index_IP == -1 || index_Port == -1 || index_File ==-1 || argc<atoi(argv[index_File])+7){
        cerr<<"Usage : ./client -i IP_Connect_to -o Port -s option -f filecount file1 file2 ...\n";
        exit(1);
    }
    socketFd = socket(AF_INET,SOCK_DGRAM,0);
    if(socketFd == -1){
        perror("socket create error!\n");
        exit(1);
    }


    client.sin_family       =   AF_INET;
    client.sin_port         =   htons(atoi(argv[index_Port]));
    client.sin_addr.s_addr  =   inet_addr(argv[index_IP]);

    server.sin_family       =   AF_INET;
    server.sin_port         =   htons(atoi(argv[index_Port]));
    server.sin_addr.s_addr  =   htonl(INADDR_ANY);

    int length = sizeof(client);

    char SendingBUF[UDP_MAX];
    memset(SendingBUF,'\0',UDP_MAX);
    /*
    for(int i=0 ;i<40;i++){
        printf("%d",int(SendingBUF[i]));
    }
    printf("\n");
    */
    struct TcpHEADER SendingPacket;
    struct TcpHEADER RecvingPacket;
    //let's do three way handshake

    SendingPacket.Source_Port          =   My_Source_Port;
    SendingPacket.Destination_Port     =   atoi(argv[index_Port]);
    SendingPacket.Sequence_Number      =   My_Sequence_Number;
    SendingPacket.Ack_Number           =   0;
    SendingPacket.Data_Offset          =   20;
    SendingPacket.SYN                  =   1;
    makePacket(SendingPacket,SendingBUF,UDP_MAX);
    //sending sync
    if(sendto(socketFd, SendingBUF, sizeof(SendingBUF), 0, (const struct sockaddr *) &client, sizeof(client))<0){
        perror("send error!");
    }
    if(recvfrom(socketFd, &ReceivingBUF, UDP_MAX, 0, (struct sockaddr*)&server, (socklen_t *)&length)<0){
            perror("recv error!");
    }
    else{
        charToTcp(RecvingPacket,ReceivingBUF);
        server_s_sequence_number = RecvingPacket.Sequence_Number;
        if(Debug_Displaying_Packet){
            cout<<"Receving Packet:\n";
            displayPacket(RecvingPacket);
        }
    }
    SendingPacket.Source_Port          =   My_Source_Port;
    SendingPacket.Destination_Port     =   atoi(argv[index_Port]);
    SendingPacket.Sequence_Number      =   ++My_Sequence_Number;
    SendingPacket.Ack_Number           =   RecvingPacket.Sequence_Number+1;
    SendingPacket.Data_Offset          =   20;
    SendingPacket.SYN                  =   0;
    SendingPacket.ACK                  =   1;
    if(Debug_Displaying_Packet){
        cout<<"Sending Packet:\n";
        displayPacket(SendingPacket);
    }
    makePacket(SendingPacket,SendingBUF,UDP_MAX);
    if(sendto(socketFd, SendingBUF, sizeof(SendingBUF), 0, (const struct sockaddr *) &client, sizeof(client))<0){
        perror("send error!");
    }

    
    SendingPacket.Source_Port          =   My_Source_Port;
    SendingPacket.Destination_Port     =   atoi(argv[index_Port]);
    SendingPacket.Sequence_Number      =   ++My_Sequence_Number;
    SendingPacket.Ack_Number           =   RecvingPacket.Sequence_Number+1;
    SendingPacket.Data_Offset          =   20;
    SendingPacket.SYN                  =   0;
    SendingPacket.ACK                  =   1;
    if(Debug_Displaying_Packet){
        cout<<"Sending Packet:\n";
        displayPacket(SendingPacket);
    }
    makePacket(SendingPacket,SendingBUF,UDP_MAX);
    if(sendto(socketFd, SendingBUF, sizeof(SendingBUF), 0, (const struct sockaddr *) &client, sizeof(client))<0){
        perror("send error!");
    }
    
    //requesting file !!
    for(int i = 0 ;i <atoi(argv[index_File]);i++){
        int fd;
        cout<<"requesting\t"<<argv[index_File+i+1]<<"\n";
        SendingPacket.Source_Port          =   My_Source_Port;
        //cout<<"My source port:"<<My_Source_Port<<"\n";
        SendingPacket.Destination_Port     =   atoi(argv[index_Port]);
        SendingPacket.Sequence_Number      =   My_Sequence_Number+24+strlen(argv[index_File+i+1]);
        My_Sequence_Number+=24+strlen(argv[index_File+i+1]);
        SendingPacket.Data_Offset          =   24;
        SendingPacket.SYN                  =   0;
        //so i need to tell which is start and the end of the file tranfering
        //expecting after send the packet , the server will send data back directly
        //keep receiving until the option for the end of the file show up , and the end of the loop

        makePacket(SendingPacket,SendingBUF,UDP_MAX);
        SendingBUF[20]                     = 1;
        SendingBUF[21]                     = 0;
        SendingBUF[22]                     = 0;
        SendingBUF[23]                     = 0;
        
        memcpy(SendingBUF+24,argv[index_File+i+1],strlen(argv[index_File+i+1]));         //50 for the length of the file is enough i think
        memset(SendingBUF+24+strlen(argv[index_File+i+1]),0,100);
        if(sendto(socketFd, SendingBUF, sizeof(SendingBUF), 0, (const struct sockaddr *) &client, sizeof(client))<0){
            perror("send error!");
        }
        /**
         *      here are missing some code to open file to write 
         *      making in 150-154
         * 
         * 
         * 
        */
        fd = open(argv[index_File+i+1],O_CREAT|O_RDWR);
        if(fd == -1){
            perror("creating or opening file error\n");
            exit(1);
        }
        int endOfFile_Indicator = 0;
        uint32_t size_of_this_tranmission = 0;
        while(!endOfFile_Indicator){
            if(recvfrom(socketFd, &ReceivingBUF, UDP_MAX, 0, (struct sockaddr*)&server, (socklen_t *)&length)<0){
                perror("recv error!");
            }
            else{
                charToTcp(RecvingPacket,ReceivingBUF);
                if(Debug_Displaying_Packet){
                    cout<<"Receving Packet:\n";
                    displayPacket(RecvingPacket);
                    //cout<<"return from request\n";
                    
                }
                size_of_this_tranmission = RecvingPacket.Sequence_Number - server_s_sequence_number;
                size_of_this_tranmission -= RecvingPacket.Data_Offset;
                server_s_sequence_number = RecvingPacket.Sequence_Number;
                cout<<"receving: "<<size_of_this_tranmission<<" bytes\n";
                cout<<"extrating "<<size_of_this_tranmission+RecvingPacket.Data_Offset<<"\n";
                if(checkSum(ReceivingBUF,(size_of_this_tranmission+RecvingPacket.Data_Offset),RecvingPacket,0)){
                    if(RecvingPacket.Data_Offset!=20){  //means it might not a regular data packet
                                                        //but consider that if the udp transport separate the TCP packet , so we also need an indicator of that situation
                        //cout<<"well didn't go well "<<ReceivingBUF[20]<<"\n";
                        if(int(ReceivingBUF[20])==2){
                            //preparing to close the file
                            close(fd);
                            server_s_sequence_number = RecvingPacket.Sequence_Number;
                            endOfFile_Indicator = 1;
                            break;
                            //close file
                        }
                        else if(int(ReceivingBUF[20])==3){
                            //just ignore and concat the file
                        }
                        else if(int(ReceivingBUF[20])==6){
                            //a bad file request // maybe the file is not exist
                            cout<<"bad request exiting\n";
                            exit(6);
                        }
                    }
                    write(fd,ReceivingBUF+RecvingPacket.Data_Offset,size_of_this_tranmission);
                    //cout<<"receving: "<<size_of_this_tranmission<<" bytes\n";
                    //cout<<"the message: "<<ReceivingBUF[RecvingPacket.Data_Offset]<<"\n";
                    /*
                    *   write the file
                    * 
                    * 
                    * 
                    * 
                    */
                    SendingPacket.Source_Port          =   My_Source_Port;
                    SendingPacket.Destination_Port     =   atoi(argv[index_Port]);
                    SendingPacket.Sequence_Number      =   ++My_Sequence_Number;
                    SendingPacket.Ack_Number           =   server_s_sequence_number+1;
                    SendingPacket.Data_Offset          =   20;
                    SendingPacket.SYN                  =   0;
                    SendingPacket.ACK                  =   1;
                    if(Debug_Displaying_Packet){
                        cout<<"Sending Packet:\n";
                        displayPacket(SendingPacket);
                    }
                    makePacket(SendingPacket,SendingBUF,UDP_MAX);
                    if(sendto(socketFd, SendingBUF, 21, 0, (const struct sockaddr *) &client, sizeof(client))<0){
                        perror("send error!");
                    }
                }
                else{
                    cout<<"checkSum error\n";
                    exit(1);
                    if(sendto(socketFd, SendingBUF, 21, 0, (const struct sockaddr *) &client, sizeof(client))<0){
                        perror("send error!");
                    }
                    if(sendto(socketFd, SendingBUF, 21, 0, (const struct sockaddr *) &client, sizeof(client))<0){
                        perror("send error!");
                    }
                    if(sendto(socketFd, SendingBUF, 21, 0, (const struct sockaddr *) &client, sizeof(client))<0){
                        perror("send error!");
                    }
                }
            }
        }
    }

}