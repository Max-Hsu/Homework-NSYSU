/*  svshm_xfr_writer.c

   Read buffers of data data from standard input into a System V shared memory
   segment from which it is copied by svshm_xfr_reader.c

   We use a pair of binary semaphores to ensure that the writer and reader have
   exclusive, alternating access to the shared memory. (I.e., the writer writes
   a block of text, then the reader reads, then the writer writes etc). This
   ensures that each block of data is processed in turn by the writer and
   reader.

   This program needs to be started before the reader process as it creates the
   shared memory and semaphores used by both processes.

   Together, these two programs can be used to transfer a stream of data through
   shared memory as follows:

        $ svshm_xfr_writer < infile &
        $ svshm_xfr_reader > out_file
*/
typedef enum { FALSE, TRUE } Boolean;
#include <sys/types.h>          /* For portability */
#include <sys/sem.h>        /* Definition of semun union */
#include "svshm_xfr.h"
#include "binary_sems.c"
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
struct shmseg *shmp;
sem_t semas;
pthread_mutex_t semMutex=PTHREAD_MUTEX_INITIALIZER;
void * writer(void * ya){
    sem_wait(&semas);
    //printf("in writer\n");
    char buf[1024]={0};
    char buff[1024]={0};
    int buf_c;
    int semid, shmid, bytes, xfrs;
    /*
    union semun dummy;


    semid = semget(SEM_KEY, 2, IPC_CREAT | OBJ_PERMS);
    if (semid == -1)
        errExit("semget");

    if (initSemAvailable(semid, WRITE_SEM) == -1)
        errExit("initSemAvailable");
    if (initSemInUse(semid, READ_SEM) == -1)
        errExit("initSemInUse");
    */
    /* Create shared memory; attach at address chosen by system */

    shmid = shmget(SHM_KEY, sizeof(struct shmseg), IPC_CREAT | OBJ_PERMS);
    if (shmid == -1)
        errExit("shmget");

    shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *) -1)
        errExit("shmat");

    /* Transfer blocks of data from stdin to shared memory */

    for (xfrs = 0, bytes = 0; ; xfrs++, bytes += buf_c) {
        /*
        if (reserveSem(semid, WRITE_SEM) == -1)
            errExit("reserveSem");
        printf("sema\n");
        */
        buf_c = read(STDIN_FILENO, buf, BUF_SIZE);
        //printf("%s\n",shmp->buf);
        if (buf_c == -1)
            errExit("read");
        /*
        if (releaseSem(semid, READ_SEM) == -1)
            errExit("releaseSem");
        */
        //printf("sema end\n");
        /* Have we reached EOF? We test this after giving the reader
           a turn so that it can see the 0 value in shmp->cnt. */
        //printf("%d\n",buf_c);
        if (buf_c == 0)
            break;
        strcat(buff,buf);
    }
    //printf("%s",buff);
    strcpy(shmp->buf,buff);
    shmp->cnt=bytes;
    /* Wait until reader has let us have one more turn. We then know
       reader has finished, and so we can delete the IPC objects. */
    /*
    if (reserveSem(semid, WRITE_SEM) == -1)
        errExit("reserveSem");

    if (semctl(semid, 0, IPC_RMID, dummy) == -1)
        errExit("semctl");
    */
    /*
    if (shmdt(shmp) == -1)
        errExit("shmdt");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        errExit("shmctl");
    */
    fprintf(stderr, "Sent %d bytes (%d xfrs)\n", bytes, xfrs);
    sem_post(&semas);
    //exit(EXIT_SUCCESS);

}
void * reader(void * dummya){
    sem_wait(&semas);
    //printf("in reader\n");
    int semid, shmid, xfrs, bytes;
    //struct shmseg *shmp;

    /* Get IDs for semaphore set and shared memory created by writer */
    /*
    semid = semget(SEM_KEY, 0, 0);
    if (semid == -1)
        errExit("semget");
    */
    shmid  = shmget(SHM_KEY, 0, 0);
    if (shmid == -1)
        errExit("shmget");

    /* Attach shared memory read-only, as we will only read */

    shmp = shmat(shmid, NULL, SHM_RDONLY);
    if (shmp == (void *) -1)
        errExit("shmat");
    //printf("ok\n");
    /* Transfer blocks of data from shared memory to stdout */

    for (xfrs = 0, bytes = 0; ; xfrs++) {
        /*
        if (reserveSem(semid, READ_SEM) == -1)
            errExit("reserveSem");
        */
        if (shmp->cnt == bytes)                     /* Writer encountered EOF */
            break;
        bytes += shmp->cnt;

        if (write(STDOUT_FILENO, shmp->buf, shmp->cnt) != shmp->cnt)
            fatal("partial/failed write");
        /*
        if (releaseSem(semid, WRITE_SEM) == -1)
            errExit("releaseSem");
        */
    }
    xfrs=0;
    for(int w=bytes;w>=0;w--){
        if(shmp->buf[w]=='\n'){
            xfrs++;
        }
    }
    if (shmdt(shmp) == -1)
        errExit("shmdt");

    /* Give writer one more turn, so it can clean up */
    /*
    if (releaseSem(semid, WRITE_SEM) == -1)
        errExit("releaseSem");
    */
    fprintf(stderr, "\nReceived %d bytes (%d xfrs)\n", bytes, xfrs);
    //exit(EXIT_SUCCESS);
    sem_post(&semas);
}


int main(int argc, char *argv[])
{


    /* Create set containing two semaphores; initialize so that
       writer has first access to shared memory. */
    pthread_t threadID_1;
    pthread_t threadID_2;
    sem_init(&semas,0,1);
    pthread_create(&threadID_1,NULL,writer,NULL);
    //sleep(1);
    pthread_create(&threadID_2,NULL,reader,NULL);
    sleep(1);
    //printf("create\n");

    pthread_join(threadID_1,NULL);
    sleep(1);
    pthread_join(threadID_2,NULL);

    return 0;
}
