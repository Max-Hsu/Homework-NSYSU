#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

#define channel_clean 56 //80*0.7
#define channel_crowded 24 //80*0.3
#define device_clean 0.3
#define device_crowded 0.7

#define hopping_time 625
#define time_for_test 1
#define all_channel 80

//#define bad_channel_value 0.65
int device_to_test[]= {40,80};
int alarm_status=1;
long all_collision=0;
long all_hop=0;
int channel_hop[80]= {0};
int channel_collision[80]= {0};
int bad_channel[80]= {0};
sem_t semas[all_channel];
void clean(int x)
{
    if(x==1)
    {
        for(int i=0; i<all_channel; i++)
        {
            channel_hop[i]=0;
            channel_collision[i]=0;
            bad_channel[i]=0;
        }
    }
    else if(x==2)
    {
        for(int i=0; i<all_channel; i++)
        {
            channel_hop[i]=0;
            channel_collision[i]=0;
        }
    }

}
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
            channel_hop[decide_channel]++;
            channel_collision[decide_channel]++;
            //printf("collision\n");
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            channel_hop[decide_channel]++;
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }
    }
    all_collision+=collision;
    all_hop+=hop;
    printf("%ld after %d  %d \n",pthread_self(),collision,hop);

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
            channel_hop[decide_channel]++;
            channel_collision[decide_channel]++;
            //printf("collision\n");
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            channel_hop[decide_channel]++;
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }
    }
    all_collision+=collision;
    all_hop+=hop;
    printf("%ld after %d  %d \n",pthread_self(),collision,hop);
}

void * tester_clean_method(void * timea)
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
        int offseta=0;
        status_trywait=sem_trywait(&semas[decide_channel]);
        hop++;

        if(status_trywait==-1)
        {
            int block_state=1;
            for(int q=0; q<2; q++)
            {
                offseta++;
                int plus=decide_channel+offseta;
                if(plus>=all_channel)
                {
                    plus-=all_channel;
                }
                int minusa=decide_channel-offseta;
                if(minusa<0)
                {
                    minusa+=all_channel;
                }
                if(sem_trywait(&semas[plus])==0)
                {
                    sem_post(&semas[plus]);
                    block_state=0;
                    break;
                }
                if(sem_trywait(&semas[minusa])==0)
                {
                    sem_post(&semas[minusa]);
                    block_state=0;
                    break;
                }

            }
            if(block_state)
            {
                //printf("coll\n");
                collision++;
                channel_hop[decide_channel]++;
                channel_collision[decide_channel]++;
            }
            //printf("collision\n");
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            channel_hop[decide_channel]++;
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }

    }
    all_collision+=collision;
    all_hop+=hop;
    printf("cl:%ld after %d  %d \n",pthread_self(),collision,hop);

}
void * tester_crowded_method(void * timea)
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
        int offseta=0;
        status_trywait=sem_trywait(&semas[decide_channel]);
        hop++;
        if(status_trywait==-1)
        {
            int block_state=1;
            for(int q=0; q<2; q++)
            {
                offseta++;
                int plus=decide_channel+offseta;
                if(plus>=all_channel)
                {
                    plus-=all_channel;
                }
                int minusa=decide_channel-offseta;
                if(minusa<0)
                {
                    minusa+=all_channel;
                }
                if(sem_trywait(&semas[plus])==0)
                {
                    sem_post(&semas[plus]);
                    block_state=0;
                    break;
                }
                if(sem_trywait(&semas[minusa])==0)
                {
                    sem_post(&semas[minusa]);
                    block_state=0;
                    break;
                }

            }
            if(block_state)
            {
                //printf("coll\n");
                collision++;
                channel_hop[decide_channel]++;
                channel_collision[decide_channel]++;
            }
            usleep(hopping_time);
        }
        else
        {
            //printf("%d  %d  %d hello\n",getpid(),status_trywait,decide_channel);
            channel_hop[decide_channel]++;
            usleep(hopping_time);
            sem_post(&semas[decide_channel]);
        }
    }
    all_collision+=collision;
    all_hop+=hop;

    printf("cr:%ld after %d  %d \n",pthread_self(),collision,hop);
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
    signal(SIGALRM,alarm_call);
    pthread_t tid [all_channel];
    pthread_t tid_method [all_channel];

    for(int k=0; k<2; k++)
    {
        for(float bad_channel_value=0.1; bad_channel_value<1; bad_channel_value+=0.1)
        {
            clean(1);
            all_collision=0;
            all_hop=0;
            alarm_status=1;
            sleep(1);
            int device_now=device_to_test[k];
            for(int i=0; i<all_channel; i++)
            {
                sem_init(&semas[i],0,1);
            }
            //scanf("%d",&test_time);

            for(int i=0; i<device_now*device_crowded; i++)
            {
                //printf("%d\n",i);
                pthread_create(&tid[i],NULL,tester_crowded,(void *)test_time);
            }
            for(int i=device_now*device_crowded; i<(device_now*device_crowded+device_now*device_clean); i++)
            {
                //printf("%d\n",i);
                pthread_create(&tid[i],NULL,tester_clean,(void *)test_time);
            }
            for(int i=0; i<device_now; i++)
            {
                pthread_join(tid[i],NULL);
            }
            printf("device: %d    after: %d sec \t total collision:%ld  \t total hop:%ld  \t probability: %lf\n",device_to_test[k],time_for_test,all_collision,all_hop,(double)all_collision/all_hop);

            for(int i=0; i<all_channel; i++)
            {
                if(bad_channel_value<((double)channel_collision[i]/channel_hop[i]))
                {
                    bad_channel[i]=1;
                    printf("%d %lf\n",i,(double)channel_collision[i]/channel_hop[i]);
                    printf("bad : %d\n",i);
                }
                else
                {
                    printf("%d %lf\n",i,(double)channel_collision[i]/channel_hop[i]);
                }
            }

            for(int i=0; i<all_channel; i++)
            {
                sem_destroy(&semas[i]);
            }

            sleep(1);
            clean(2);
            all_collision=0;
            all_hop=0;
            alarm_status=1;

            for(int i=0; i<all_channel; i++)
            {
                sem_init(&semas[i],0,1);
            }

            for(int i=0; i<device_now*device_crowded; i++)
            {
                //printf("%d\n",i);
                pthread_create(&tid_method[i],NULL,tester_crowded_method,(void *)test_time);
            }
            for(int i=device_now*device_crowded; i<(device_now*device_crowded+device_now*device_clean); i++)
            {
                //printf("%d\n",i);
                pthread_create(&tid_method[i],NULL,tester_clean_method,(void *)test_time);
            }
            for(int i=0; i<device_now; i++)
            {
                pthread_join(tid_method[i],NULL);
            }
            printf("device: %d    after: %d sec \t total collision:%ld  \t total hop:%ld  \t probability: %lf\n",device_to_test[k],time_for_test,all_collision,all_hop,(double)all_collision/all_hop);

            for(int i=0; i<all_channel; i++)
            {
                sem_destroy(&semas[i]);
            }


        }
    }
    return 0;
}
