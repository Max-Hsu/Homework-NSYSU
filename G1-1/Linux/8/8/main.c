#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/msg.h>
#define charsize 80
struct msgbufa
{
    long mtype;         /* type of message */
    char mtext[charsize];      /* message text */
};
int data_num,data_rate,consumer_num,buffer_size;
int pgid;
int child_status=1;
void handler(int signala,siginfo_t *info,void *ucontext)
{
    //printf("%d\n",info->si_int);
}
void handler_to_end(int signala)
{
    child_status=0;
    //printf("hello\n");
}
int main(int argc,char *argv[])
{
    FILE *deletea;
    char deletebuf[charsize];
    int deletecount=1;
    snprintf(deletebuf,charsize,"%d.txt",deletecount);
    while(deletea=fopen(deletebuf,"r+"))
    {
        fclose(deletea);
        remove(deletebuf);
        deletecount++;
        snprintf(deletebuf,charsize,"%d.txt",deletecount);
    }

    if(argc!=5)
    {
        printf("wrong input");
        exit(0);
    }
    data_num=atoi(argv[1]);
    data_rate=atoi(argv[2]);
    consumer_num=atoi(argv[3]);
    buffer_size=atoi(argv[4]);

    static int total_rec[30000]= {0};
    int pid_c;
    /*
    sigset_t to_block;
    sigfillset(&to_block);
    sigdelset(&to_block,SIGUSR1);
    */
    struct sigaction act;
    act.sa_handler=handler;
    sigfillset(&act.sa_mask);
    sigdelset(&act.sa_mask,SIGCONT);
    sigdelset(&act.sa_mask,SIGCLD);
    act.sa_flags=SA_SIGINFO;
    sigaction(SIGCONT,&act,NULL);

    struct sigaction act_usr2;
    act_usr2.sa_handler=handler_to_end;
    sigaction(SIGCLD,&act_usr2,NULL);
    act_usr2.sa_flags=0;

    key_t key;
    key=ftok("/tmp",1);

    key_t key_n;
    key_n=ftok("/home",2);

    pid_t pid[30000];

    /*
    int msgflag;
    struct msgbufa * msgp;
    int msgid;

    msgid=msgget(IPC_PRIVATE,0666);
    */

    int shmid_n=shmget(key_n,charsize*buffer_size*sizeof(char),IPC_CREAT|0666);
    char *shmp_n;
    shmp_n=shmat(shmid_n,NULL,0);

    for(int i=0; i<consumer_num; i++)
    {
        pid[i]=fork();
        switch(pid[i])
        {
        case 0:

            setpgid(pid[i],1);
            //printf("%d\n",getpgid(0));
            pgid=getpgrp();
            //pgid=getpgid(0);
            int totalcc=0;

            int shmid_r=shmget(key,charsize*buffer_size*sizeof(char),0666);
            char *shmp_r;
            shmp_r=shmat(shmid_r,NULL,0);

            int shmid_rn=shmget(key_n,charsize*buffer_size*sizeof(char),0666);
            char *shmp_rn;
            shmp_rn=shmat(shmid_rn,NULL,0);

            while(child_status)
            {
                //printf("Waiting\n");
                /*
                struct msgbufa *rcmsg;
                rcmsg=(struct msgbufa *)malloc(sizeof(long)+charsize*sizeof(char));
                */


                pid_c=pgid;


                sigsuspend(&act.sa_mask);

                if(child_status==1)
                {
                    /*
                    msgrcv(msgid,&rcmsg,charsize,0,0);
                    printf("recv:%s\n",rcmsg->mtext);
                    */
                    //printf("rec:%s\n",shmp_rn);
                    int rn_c=atoi(shmp_rn);
                    //printf("%d\n",getpid());

                    /*
                    printf("message:%s\n",shmp_r+rn_c*charsize);
                    */

                    //printf("pid:%d\n",getpid()-pid_c);
                    /*
                    total_rec[getpid()-pid_c]++;
                    totalaa++;
                    */
                    totalcc++;
                    //printf("plus\n");
                }
            }
            char txtbuf[10000];
            snprintf(txtbuf,10000,"%d.txt",getpid()-pid_c);
            FILE *writera=fopen(txtbuf,"w+");
            fprintf(writera,"%d\n",totalcc);
            fflush(writera);
            printf("cc count:%d  %d\n",getpid()-pid_c,totalcc);
            printf("BYE\n");
            fclose(writera);
            sleep(1);
            /*
            if (shmdt(shmp_r) == -1)
                perror("shmdt");
            if (shmctl(shmid_n, IPC_RMID, 0) == -1)
                perror("shmctl");

            if (shmdt(shmp_rn) == -1)
                perror("shmdt");
            if (shmctl(shmid_rn, IPC_RMID, 0) == -1)
                perror("shmctl");
            */
            return 0;

        }
    }

    int shmid=shmget(key,charsize*buffer_size*sizeof(char),IPC_CREAT|0666);
    char *shmp;
    shmp=shmat(shmid,NULL,0);


    //printf("done!!\n");



    printf("i am pgid %d\n",getpgrp());

    /*
    sleep(1);
    kill(0,SIGUSR1);
    sleep(1);
    kill(0,SIGUSR1);
    sleep(1);
    kill(0,SIGUSR1);
    */

    union sigval value;
    value.sival_int=2;
    //sigqueue(pgid,SIGUSR1,value);
    int counter;

    for(int i=0; i<data_num; i++)
    {
        counter=i%buffer_size;
        char data_block[charsize];
        snprintf(data_block,charsize,"This is message %d",i);
        //printf("%s\n",data_block);
        memcpy(shmp+counter*charsize,data_block,charsize);
        //msgp=(struct msgbufa *)malloc(sizeof(long)+charsize*sizeof(char));
        char bufff[80];
        snprintf(bufff,charsize,"%d",counter);
        memcpy(shmp_n,bufff,charsize);
        printf("send:%s\n",shmp_n);
        /*
        strcpy(msgp->mtext,bufff);
        printf("msgp:%s\n",msgp->mtext);
        msgp->mtype=1;
        msgsnd(msgid,&msgp,charsize,IPC_NOWAIT);
        */

        kill(0,SIGCONT);
        usleep(data_rate);
        printf("%s\n",(shmp+counter*charsize));
    }

    sleep(3);
    int totals=0;


    kill(0,SIGCLD);
    //printf("%d",child_status);
    waitpid(0,NULL,0);
    for(int i=1; i<=consumer_num+2; i++)
    {
        int numaa=0;
        char txtbufa[10000];
        snprintf(txtbufa,10000,"%d.txt",i);
        FILE *reada=fopen(txtbufa,"r+");
        if(reada==NULL)
        {
            if(i==1)
            {
                fclose(reada);
                i=3;
                snprintf(txtbufa,10000,"%d.txt",i);
                FILE *reada=fopen(txtbufa,"r+");
                //continue;
            }
            else
            {
                break;
            }
        }
        fscanf(reada,"%d\n",&numaa);
        totals+=numaa;
        printf("%d numaa=%d\n",i,numaa);
        fclose(reada);
    }
    printf("\n\n%d\n\n",totals);
    if (shmdt(shmp) == -1)
        perror("shmdt");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        perror("shmctl");
    if (shmdt(shmp_n) == -1)
        perror("shmdt");
    if (shmctl(shmid_n, IPC_RMID, 0) == -1)
        perror("shmctl");

        deletecount=1;
        snprintf(deletebuf,charsize,"%d.txt",deletecount);
        while(deletea=fopen(deletebuf,"r+"))
    {
        fclose(deletea);
        remove(deletebuf);
        deletecount++;
        snprintf(deletebuf,charsize,"%d.txt",deletecount);
    }
    return 0;
}
