#include <iostream>
#include "server-thread.hpp"
#include <vector>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "TcpHeader.hpp"
#include <netinet/ip.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

void * server_thread(void * args){
    struct PassingToThread * here = (PassingToThread *) args;
    char requestingBUF [UDP_MAX];
    int fd;
    char filename[50];
    vector<struct unpackOption> Options;
    struct stat stat_file;
    ssize_t file_size = 0;
    ssize_t accumulate_size = 0;
    int cwnd = 1;
    while(1){
        pthread_cond_wait(&(here->cond_signal),&(here->lock));
        //cout<<"thread open\n";
        int fd;
        int init_i = 1;
        uint32_t my_Threshold = Threshold;
        ssize_t file_read_size;
        
        if(here->ReceivingPacket.Data_Offset>20){       // 1.requesting file
                                                        // 2.sack , but not yet implement
            if(here->ReceivingBUF_PTH[20]==1){
                memcpy(filename,here->ReceivingBUF_PTH+here->ReceivingPacket.Data_Offset,here->Bind_data.Packet_Size-here->ReceivingPacket.Data_Offset);
                cout<<"receiving a request : "<<filename<<"\n";
                fd = open(filename,O_RDONLY);
                if(fd == -1){
                    cout<<"file error : no such a file\n";
                    here->SendingPacket.Source_Port        =   here->ReceivingPacket.Destination_Port;
                    here->SendingPacket.Destination_Port   =   here->ReceivingPacket.Source_Port;
                    here->SendingPacket.Sequence_Number    =   here->My_Sequence_Number+24;
                    here->SendingPacket.Data_Offset        =   24;
                    here->SendingPacket.ACK                =   0;
                    makePacket(here->SendingPacket,here->SendingBUF_PTH,UDP_MAX);
                    here->SendingBUF_PTH [20] = 6;
                    here->SendingBUF_PTH [21] = 0;
                    here->SendingBUF_PTH [22] = 0;
                    here->SendingBUF_PTH [23] = 0;

                    if(sendto(here->sockFd_PTH, here->SendingBUF_PTH, UDP_MAX, 0, (const struct sockaddr *) here->client, sizeof(*(here->client)))<0){
                        perror("send error!");
                    }
                    here->readOK = -1;
                    pthread_exit(NULL);
                }
            }
            stat(filename,&stat_file);
            file_size = stat_file.st_size;
            cout<<"the file is "<<file_size<<" large\n";
        }
        ssize_t actual_can_read = (file_size-accumulate_size) < cwnd ? (file_size-accumulate_size): cwnd;


        if(accumulate_size == file_size){
            /**
             * 
             * send end packet
            */
            here->SendingPacket.Source_Port        =   here->ReceivingPacket.Destination_Port;
            here->SendingPacket.Destination_Port   =   here->ReceivingPacket.Source_Port;
            here->SendingPacket.Sequence_Number    =   (here->My_Sequence_Number)+24+cwnd;
            here->My_Sequence_Number+= (24+cwnd);
            here->SendingPacket.Data_Offset        =   24;
            here->SendingPacket.ACK                =   0;
            here->SendingBUF_PTH[20]               =   2;
            here->SendingBUF_PTH[21]               =   0;
            here->SendingBUF_PTH[22]               =   0;
            here->SendingBUF_PTH[23]               =   0;
            makePacket(here->SendingPacket,here->SendingBUF_PTH,UDP_MAX);
            if(sendto(here->sockFd_PTH, here->SendingBUF_PTH, 24, 0, (const struct sockaddr *) here->client, sizeof(*(here->client)))<0){
                perror("send error!");
            }
            here->readOK = -1;
            cout<<"tranmission done bye\n";
            pthread_exit(NULL);
        }
        else if(here->ReceivingPacket.ACK == 1 || init_i){      // the ack come , prepare file!!
            /*
                missing changing cwnd code
                let's just first test if the tranmission work
            
            */
            init_i = 0;
            cout<<"sending "<<actual_can_read<<" bytes\n";
            file_read_size = read(fd,requestingBUF,actual_can_read);
            accumulate_size += actual_can_read;
            cout<<"cwnd : "<<cwnd<<" rwnd : "<<here->ReceivingPacket.Window_Size<<" Threshold : "<<my_Threshold<<"\n";
            here->SendingPacket.Source_Port        =   here->ReceivingPacket.Destination_Port;
            here->SendingPacket.Destination_Port   =   here->ReceivingPacket.Source_Port;
            here->SendingPacket.Sequence_Number    =   (here->My_Sequence_Number)+20+actual_can_read;
            //cout<<"the answer is: "<<actual_can_read<<"\n";//(((file_size - accumulate_size) < cwnd) ? (here->My_Sequence_Number)+(file_size-accumulate_size+20):(here->My_Sequence_Number)+20+cwnd)<<"\n";
            
            here->My_Sequence_Number+= (20+actual_can_read);
            here->SendingPacket.Data_Offset        =   20;
            here->SendingPacket.ACK                =   0;
            makePacket(here->SendingPacket,here->SendingBUF_PTH,UDP_MAX);
            memcpy(((here->SendingBUF_PTH)+20),requestingBUF,actual_can_read);
            //cout<<"sending "<<here->SendingBUF_PTH[20]<<"\n";
            checkSum(here->SendingBUF_PTH,20+actual_can_read,here->SendingPacket,1);

            if(sendto(here->sockFd_PTH, here->SendingBUF_PTH, 20+actual_can_read, 0, (const struct sockaddr *) here->client, sizeof(*(here->client)))<0){
                perror("send error!");
            }
            cwnd = cwnd*2 < my_Threshold ? cwnd*2 : cwnd;
        }
        here->readOK = 1;
        //sleep(1);

    }


}

/* 
int main(){
    char ax[5] = "1xx\0";
    char bx[5] = "2x\0";
    char cx[5] = "32xx";
    struct thread_test * a = new(struct thread_test);
    struct thread_test * b = new(struct thread_test);
    a->cond_signal  = PTHREAD_COND_INITIALIZER;
    b->cond_signal  = PTHREAD_COND_INITIALIZER;

    a->lock         = PTHREAD_MUTEX_INITIALIZER;
    b->lock         = PTHREAD_MUTEX_INITIALIZER;

    a->ReceivingBUF_PTH = ax;
    b->ReceivingBUF_PTH = bx;


    pthread_create(&(a->tid),NULL,server_thread,a);
    pthread_create(&(b->tid),NULL,server_thread,b);


    sleep(1);
    pthread_cond_signal(&(a->cond_signal));
    usleep(100);
    a->ReceivingBUF_PTH = cx;
    sleep(5);
    pthread_cond_signal(&(b->cond_signal));

    sleep(1);
    pthread_cond_signal(&(a->cond_signal));
    sleep(1);
    cout<<"bye\n";
} */