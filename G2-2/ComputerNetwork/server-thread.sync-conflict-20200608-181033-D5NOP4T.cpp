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
    char requestingFile [50];
    int fd;
    char filename[50];
    vector<struct unpackOption> Options;
    while(1){
        pthread_cond_wait(&(here->cond_signal),&(here->lock));
        //cout<<"thread open\n";
        int fd;
        if(here->RecvivingPacket.Data_Offset>20){       // 1.requesting file
                                                        // 2.sack , but not yet implement
            if(here->ReceivingBUF_PTH[20]==1){
                memcpy(filename,here->ReceivingBUF_PTH+here->RecvivingPacket.Data_Offset,here->Bind_data.Packet_Size-here->RecvivingPacket.Data_Offset);
                cout<<"receiving a request : "<<filename<<"\n";
                fd = open(filename,O_RDONLY);
                if(fd == -1){
                    here->SendingPacket.Source_Port        =   here->RecvivingPacket.Destination_Port;
                    here->SendingPacket.Destination_Port   =   here->RecvivingPacket.Source_Port;
                    here->SendingPacket.Sequence_Number    =   here->My_Sequence_Number+24;
                    here->SendingPacket.Data_Offset        =   24;
                    here->SendingPacket.ACK                =   0;
                    makePacket(here->SendingPacket,here->SendingBUF_PTH,UDP_MAX);
                    if(sendto(here->socketFd_PTH, here->SendingBUF_PTH, sizeof(here->SendingBUF_PTH), 0, (const struct sockaddr *) &client, sizeof(client))<0){
                        perror("send error!");
                    }
                }
            }

        }

        else if(here->Header.ACK == 1){      // the ack come , prepare file!!


        }


        here->readOK = 1;
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