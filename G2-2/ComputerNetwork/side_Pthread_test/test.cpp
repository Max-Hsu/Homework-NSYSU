#include <iostream>
#include "test.hpp"

using namespace std;

void * server_thread(void * args){
    struct thread_test * here = (thread_test *) args;
    while(1){
        pthread_cond_wait(&(here->cond_signal),&(here->lock));
        cout<<"xx\n";
        cout<<here->ReceivingBUF_PTH<<"\n";
    }


}

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
}