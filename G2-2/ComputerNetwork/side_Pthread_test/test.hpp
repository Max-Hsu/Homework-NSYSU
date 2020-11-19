#include <pthread.h>
#include <iostream>
#include <unistd.h>

void *server_thread(void * args);
struct thread_test{
    pthread_t           tid;
    pthread_cond_t      cond_signal;
    pthread_mutex_t     lock;
    char *              ReceivingBUF_PTH;

};