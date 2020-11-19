#include <iostream>
#include "server-thread.hpp"

using namespace std;

void * server_thread(void * args){
    struct PassingToThread * here = (PassingToThread *) args;
    char requestingFile [50];
    int fd;

    while(1){
        pthread_cond_wait(&(here->cond_signal),&(here->lock));
        if(here->Header.Data_Offset>20){    // 1.requesting file
                                            // 2.sack , but not yet implement
            
                 
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