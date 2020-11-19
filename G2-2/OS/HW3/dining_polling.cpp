#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define Philosophers 5
#define findLeft(num) (num-1) < 0 ? (num+4)%5 : (num-1)%5

using namespace std;
class monitor{
    public:
        monitor(){
            for (int i=0;i<Philosophers;i++){
                pthread_mutex_init(&Forks[i],NULL);
            }
        }
        int take_fork(int myNum){
            int LmyNum = (findLeft(myNum));
            int lNum = -1;
            int rNum = -1;
            rNum = pthread_mutex_trylock(&Forks[myNum]);
            lNum = pthread_mutex_trylock(&Forks[LmyNum]);
            if(rNum == 0 && lNum==0){return 0;}
            else if(rNum == 0 && lNum!=0){return 1;}
            else if(rNum != 0 && lNum==0){return 2;}
            return 3;
        }
        void release_fork(int myNum , int typeLock){
            int LmyNum = (findLeft(myNum));
            if(typeLock == 0){
                pthread_mutex_unlock(&Forks[myNum]);
                pthread_mutex_unlock(&Forks[LmyNum]);
            }
            else if(typeLock==1){
                pthread_mutex_unlock(&Forks[myNum]);
            }
            else if(typeLock==2){
                pthread_mutex_unlock(&Forks[LmyNum]);
            }
        }
        ~monitor(){
            for (int i=0;i<Philosophers;i++){
                pthread_mutex_destroy(&Forks[i]);
            }
        }
    private:
        pthread_mutex_t Forks[Philosophers];

};
monitor fork_monitor;
static pthread_t tid[Philosophers];
static int aii[5] = {0,1,2,3,4};
void * PhilosopherFunction(void * args){
    int myNum = *(int *)args;
    int LmyNum = (findLeft(myNum));
    int Return_Try_fork;
    int randThinkTime = rand()%5+rand()%5;
    printf("Hi i am philosopher:%d , i am going to think %d sec\n",myNum,randThinkTime);
    sleep(randThinkTime);
    while (1){
        Return_Try_fork = fork_monitor.take_fork(myNum);
        if(Return_Try_fork == 0){
            int eating_time = rand()%15;
            printf("%d: yes i got %d %d eating_time %d\n",myNum,myNum,LmyNum,eating_time);
            sleep(eating_time);
            fork_monitor.release_fork(myNum,Return_Try_fork);
            printf("%d: i am fulled\n",myNum);
            break;
        }
        else if(Return_Try_fork==1){
            printf("%d: no i only got %d fail on %d \n",myNum,myNum,LmyNum);
            fork_monitor.release_fork(myNum,Return_Try_fork);
        }
        else if(Return_Try_fork==2){
            printf("%d: no i only got %d fail on %d \n",myNum,LmyNum,myNum);
            fork_monitor.release_fork(myNum,Return_Try_fork);
        }
        else{
            printf("%d: well,bad luck  %d %d \n",myNum,myNum,LmyNum);
        }
        int sleeping_time = rand()%10;
        printf("%d: i should shut up and wait %d\n",myNum,sleeping_time);
        sleep(sleeping_time);
    }
    pthread_exit(0);
}


int main(){
    srand(time(NULL));
    cout<<getpid()<<"\n";
    for (int i=0;i<Philosophers;i++){
        void * ai = &aii[i];
        pthread_create(&tid[i],NULL,PhilosopherFunction,ai);
    }
    for (int i=0;i<Philosophers;i++){
        pthread_join(tid[i],NULL);
    }
}
