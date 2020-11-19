#include <stdio.h>
#include <iostream>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <vector>
#include <pthread.h>
#include "TcpHeader.hpp"
#include "server.hpp"
#include "server-thread.hpp"
using namespace std;

int main(int argc , char ** argv){
    srand(time(NULL));
    int index_Port;
    int index_Option;
    int socketFd;
    uint32_t My_Sequence_Number = (rand()%10000)+1;
    index_Port  =   findArgument("-o",argv,argc);
    index_Option=   findArgument("-s",argv,argc);

    char ReceivingBUF[UDP_MAX];
    char SendingBUF[UDP_MAX];

    struct sockaddr_in server;
    struct sockaddr_in client;
    memset(&server,'\0',sizeof(server));
    memset(&client,'\0',sizeof(client));

    if(argc<3 || index_Port == -1){
        cerr<<"Usage : ./server -o Port -s option\n";
        exit(1);
    }
    
    socketFd = socket(AF_INET,SOCK_DGRAM,0);
    if(socketFd == -1){
        perror("socket create error!\n");
        exit(1);
    }

    server.sin_family       =   AF_INET;
    server.sin_port         =   htons(atoi(argv[index_Port]));
    server.sin_addr.s_addr  =   htonl(INADDR_ANY);

    if(bind(socketFd,(struct sockaddr *)&server,sizeof(server))<0){
        perror("socket bind error!\n");
        exit(1);
    }
    int length = sizeof(client);
    char receiveIP[20];
    vector<struct Bind> ListBindDone;
    vector<struct Bind> ListBindPending;
    vector<struct PassingToThread *> Server_Pthread_List;

    while(1){
        //cout<<"hello\n";
        if ((recvfrom(socketFd, &ReceivingBUF, UDP_MAX, 0, (struct sockaddr*)&client, (socklen_t *)&length)) <0) {
            perror ("recv error!");
            continue;
        }
        else{
            //when enter here , the server doesn't know the request(if the connection had already establish or not)
            struct TcpHEADER ReceivingPacket;
            struct TcpHEADER SendingPacket;
            charToTcp(ReceivingPacket,ReceivingBUF);
            if(Debug_Displaying_Packet){
                displayPacket(ReceivingPacket);
            }
            if(ReceivingPacket.SYN == 1){ //a client want to estab a connection
                //cout<<"hi SYNC here\n";
                struct Bind DataBind;
                int FindSameBind = 0;
                DataBind.ClientIp   = client.sin_addr.s_addr;
                DataBind.ClientPort = ReceivingPacket.Source_Port;
                DataBind.Last_Sequence = ReceivingPacket.Sequence_Number;
                for(int i=0 ; i<ListBindDone.size(); i++){
                    if(ListBindDone[i].ClientIp == DataBind.ClientIp && ListBindDone[i].ClientPort == DataBind.ClientPort){
                        FindSameBind = 1;
                        break;
                    }
                }

                if(!FindSameBind){
                    //send back ack for init connection
                    //cout<<"first sync\n";
                    ListBindPending.push_back(DataBind);
                    SendingPacket.Source_Port        =   ReceivingPacket.Destination_Port;
                    SendingPacket.Destination_Port   =   ReceivingPacket.Source_Port;
                    SendingPacket.Sequence_Number    =   My_Sequence_Number;
                    SendingPacket.Ack_Number         =   ReceivingPacket.Sequence_Number+1;
                    SendingPacket.Data_Offset        =   20;
                    SendingPacket.ACK                =   1;
                    makePacket(SendingPacket,SendingBUF,sizeof(SendingBUF));
                    if(Debug_Displaying_Packet){
                        displayPacket(SendingPacket);
                    }
                    if (sendto(socketFd, (const char *)SendingBUF, UDP_MAX, 0, (struct sockaddr*)&client, length) < 0) {
                        perror("send error!");
                        continue;
                    }
                }
            }
            else{   //client maybe synced , sync_pending , or just random coming
                struct Bind DataBind;
                int FindSameBindDone = 0;
                int FindSameBindPending = 0;
                int FindSameBindPendingIndex = -1;
                int FindSameBindDoneIndex = -1;
                DataBind.ClientIp   = client.sin_addr.s_addr;
                DataBind.ClientPort = ReceivingPacket.Source_Port;
                
                for(int i=0 ; i<ListBindDone.size(); i++){
                    if(ListBindDone[i].ClientIp == DataBind.ClientIp && ListBindDone[i].ClientPort == DataBind.ClientPort){
                        FindSameBindDone = 1;
                        FindSameBindDoneIndex = i;
                        break;
                    }
                }
                for(int i=0 ; i<ListBindPending.size(); i++){
                    if(ListBindPending[i].ClientIp == DataBind.ClientIp && ListBindPending[i].ClientPort == DataBind.ClientPort){
                        FindSameBindPending = 1;
                        FindSameBindPendingIndex = i;
                        break;
                    }
                }

                if(FindSameBindDone){       //already establish connection , so this is normal operation //should provide some "ls" for user to choose file?
                                            //well right now we are just calling the file name for transportation
                    /*                     //send back ack for init connection
                    SendingPacket.Source_Port        =   ReceivingPacket.Destination_Port;
                    SendingPacket.Destination_Port   =   ReceivingPacket.Source_Port;
                    SendingPacket.Sequence_Number    =   My_Sequence_Number;
                    SendingPacket.Ack_Number         =   ReceivingPacket.Sequence_Number+1;
                    SendingPacket.Data_Offset        =   0;
                    SendingPacket.ACK                =   1;
                    makePacket(SendingPacket,SendingBUF,sizeof(SendingBUF));
                    if (sendto(socketFd, (const char *)SendingBUF, sizeof(ok), 0, (struct sockaddr*)&client, length) < 0) {
                        perror("send error!");
                        continue;
                    } */
                    //********************cout<<"est done.. good job!!\n";*****************************//
                    //if packet come here , it has two type one is requesting the file or the ack..
                    //so we need to create socket for handling the situation and send file
                    //how to transfer the file? using the receiving header?
                    //but is the data important
                    //cout<<"after bind\n";
                    int index_Server_Pthread_List = -1;
                    for(int i = 0 ; i < Server_Pthread_List.size();i++){
                        if(Server_Pthread_List[i]->Bind_data.ClientIp == DataBind.ClientIp && Server_Pthread_List[i]->Bind_data.ClientPort == DataBind.ClientPort){
                            index_Server_Pthread_List = i;
                        }
                    }
                    if(index_Server_Pthread_List != -1){
                        //well just cond wake the pthread
                        //cout<<"am i stuck in here?\n";
                        Server_Pthread_List[index_Server_Pthread_List]->Bind_data.Packet_Size    = ReceivingPacket.Sequence_Number - ListBindDone[FindSameBindDoneIndex].Last_Sequence;
                        Server_Pthread_List[index_Server_Pthread_List]->Bind_data.Last_Sequence  = ReceivingPacket.Sequence_Number;
                        Server_Pthread_List[index_Server_Pthread_List]->readOK                   = 0;
                        Server_Pthread_List[index_Server_Pthread_List]->ReceivingBUF_PTH         = ReceivingBUF;
                        Server_Pthread_List[index_Server_Pthread_List]->ReceivingPacket          = ReceivingPacket;
                        pthread_cond_signal(&(Server_Pthread_List[index_Server_Pthread_List]->cond_signal));
                        while(1){
                            //cout<<"i should \n";
                            if((Server_Pthread_List[index_Server_Pthread_List]->readOK) == 1){
                                break;
                            }
                            else if((Server_Pthread_List[index_Server_Pthread_List]->readOK) == -1){
                                cout<<"exiting thread\n";
                                My_Sequence_Number = Server_Pthread_List[index_Server_Pthread_List]->My_Sequence_Number;
                                pthread_detach(Server_Pthread_List[index_Server_Pthread_List]->tid);
                                Server_Pthread_List.erase(Server_Pthread_List.begin()+index_Server_Pthread_List);
                                //sleep(1);
                                break;
                            }
                        }
                    }
                    else{       //only if the client is not found in the pthread list, create the pthread
                        //cout<<"hi\n";
                        //necessity of inner two if statement?
                        if(ReceivingPacket.Data_Offset!=20 && ReceivingBUF[20]==1){    //still has a chance of two prosability :
                                                                //1.ack or sack need to check!!!           , but we will ignore this and hand it to the thread
                                                                //2.requesting a file
                            
                                                                //a file request , so start a new thread
                                                                //check if the request client has already init the sending thread
                            cout<<"receiving a request\n";
                            struct PassingToThread * SendToPthread = new(struct PassingToThread);
                            SendToPthread->Bind_data.Packet_Size    = ReceivingPacket.Sequence_Number - ListBindDone[FindSameBindDoneIndex].Last_Sequence;
                            SendToPthread->Bind_data.Last_Sequence  = ReceivingPacket.Sequence_Number;
                            SendToPthread->Bind_data.ClientIp       = ListBindDone[FindSameBindDoneIndex].ClientIp;
                            SendToPthread->Bind_data.ClientPort     = ListBindDone[FindSameBindDoneIndex].ClientPort;
                            SendToPthread->cond_signal              = PTHREAD_COND_INITIALIZER;
                            SendToPthread->ReceivingPacket          = ReceivingPacket;
                            SendToPthread->ReceivingBUF_PTH         = ReceivingBUF;
                            SendToPthread->SendingBUF_PTH           = SendingBUF;
                            SendToPthread->SendingPacket            = SendingPacket;
                            SendToPthread->sockFd_PTH               = socketFd;
                            SendToPthread->client                   = &client;
                            SendToPthread->My_Sequence_Number       = My_Sequence_Number;
                            pthread_create(&(SendToPthread->tid),NULL,server_thread,SendToPthread);
                            usleep(500);
                            pthread_cond_signal(&(SendToPthread->cond_signal));
                            Server_Pthread_List.push_back(SendToPthread);
                            while(!(SendToPthread->readOK));
                        }
                        else{
                            cout<<"failing to recognize\n";
                        }
                    }


                    /*
                    *   normal ack , match if there is a match the thread list
                    * 
                    * 
                    *
                    */ 
                }
                else if(FindSameBindPending){
                    if(ReceivingPacket.ACK == 1 && ReceivingPacket.Ack_Number == (My_Sequence_Number +1)){
                        ListBindPending[FindSameBindPendingIndex].Packet_Size = ReceivingPacket.Sequence_Number - ListBindPending[FindSameBindPendingIndex].Last_Sequence;
                        ListBindPending[FindSameBindPendingIndex].Last_Sequence = ReceivingPacket.Sequence_Number;
                        ListBindDone.push_back(ListBindPending[FindSameBindPendingIndex]);
                        ListBindPending.erase(ListBindPending.begin()+FindSameBindPendingIndex);
                        cout<<"bind ok!!\n";
                    }
                }
                else{
                    cout<<"230\n";
                }


            }
            
            /*cout<<inet_ntop(AF_INET,&(client.sin_addr),receiveIP,INET_ADDRSTRLEN)<<"\t";
            cout<<ReceivingPacket.Source_Port     <<"\t";
            cout<<ReceivingPacket.Destination_Port<<"\t";
            cout<<ReceivingPacket.Sequence_Number <<"\t";
            cout<<ReceivingPacket.Ack_Number      <<"\t";
            cout<<int(ReceivingPacket.Data_Offset)<<"\t";
            cout<<"\n"; */

        }
    }
    sleep(1);   //we need this is because exiting the main but the pthread isn't clear , so add this for prevent incorrect memory access
}