#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#define device 2

#define channel_clean 56 //80*0.7
#define channel_crowded 24 //80*0.3
#define device_clean 0.3
#define device_crowded 0.7

#define hopping_time 625
#define time_for_test 100
#define all_channel 80
int alarm_status=1;
long all_collision=0;
long all_hop=0;
sem_t semas[all_channel];
void alarm_call(int signo)
{
    printf("alarm\n");
    alarm_status=0;
}
void * tester_clean(void * timea)
{
    int test_time=(int)timea;
    //printf("test time=%d\n",test_time);
    alarm(time_for_test);
    srand(time(NULL)+rand());
    int collision=0;
    int hop=0;
    while(alarm_status)
    {
        int status_trywait;
        int decide_channel=rand()%channel_clean;
        status_trywait=sem_trywait(&semas[decide_channel]);
        hop++;
        if(status_trywait==-1)
        {
            collision++;
            //printf("collision\n");
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }
    }
    all_collision+=collision;
    all_hop+=hop;
    //printf("%ld after %d\n",pthread_self(),collision);

}
void * tester_crowded(void * timea)
{
    int test_time=(int)timea;
    //printf("test time=%d\n",test_time);
    alarm(time_for_test);
    srand(time(NULL)+rand());
    int collision=0;
    int hop=0;
    while(alarm_status)
    {
        int status_trywait;
        int decide_channel=rand()%channel_crowded+channel_clean;
        status_trywait=sem_trywait(&semas[decide_channel]);
        hop++;
        if(status_trywait==-1)
        {
            collision++;
            //printf("collision\n");
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }
    }
    all_collision+=collision;
    all_hop+=hop;


}
void clean()
{
    all_collision=0;
    all_hop=0;
}


int main()
{
    int test_time;
    srand(time(NULL));
    /*
    struct sigaction alarm_str;
    sigemptyset(&alarm_str.sa_mask);
    alarm_str.sa_flags=0;
    alarm_str.sa_handler=handler;
    if(sigaction(SIGALRM,&alarm_str,NULL)==-1){
        perror("sigaction");
        exit(1);
    }
    */


    /*
    signal(SIGALRM,alarm_call);
    pthread_t tid [device];

    for(int i=0; i<all_channel; i++)
    {
        sem_init(&semas[i],0,1);
    }
    //scanf("%d",&test_time);

    for(int i=0; i<device; i++)
    {
        pthread_create(&tid[i],NULL,tester_crowded,(void *)test_time);
    }
    for(int i=0; i<device; i++)
    {
        pthread_join(tid[i],NULL);
    }


    */
    int device_array[80]= {0};
    int device_to_test[]= {2,10,20,30,40,50,60,70,80};


    for(long a=0; a<1600*100/2; a++)
    {
        int x=rand()%channel_crowded;
        int y=rand()%channel_crowded;
        if(x==y)
        {
            all_collision+=2;
        }
        all_hop+=2;
    }
    printf("device: %d    \t total collision:%ld  \t total hop:%ld  \t probability: %lf\n",device,all_collision,all_hop,(double)all_collision/all_hop);
    clean();
    for(int k=1; k<9; k++)
    {
        for(long a=0; a<1600*100/device_to_test[k]; a++)
        {
            for(int b=0; b<device_to_test[k]*0.7; b++)
            {
                device_array[b]=rand()%channel_clean;
            }
            for(int b=device_to_test[k]*0.7; b<device_to_test[k]; b++)
            {
                device_array[b]=(rand()%channel_crowded)+channel_clean;
            }
            for(int b=0; b<device_to_test[k]; b++)
            {
                for(int c=0; c<device_to_test[k]; c++)
                {
                    if((device_array[b]==device_array[c])&&(b!=c))
                    {
                        all_collision+=2;
                    }
                }
            }

            all_hop+=device_to_test[k];
        }
        printf("device: %d    \t total collision:%ld  \t total hop:%ld  \t probability: %lf\n",device_to_test[k],all_collision,all_hop,(double)all_collision/all_hop);
        clean();
    }





    return 0;
}
