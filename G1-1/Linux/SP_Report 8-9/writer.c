#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char shm_fn[] = "my_shm";
char sem_fn[] = "my_sem";
/**** WRITER ****/
int main()
{
    caddr_t shmptr;
    unsigned int mode;
    int shmdes, index;
    sem_t *sem_des;
    int SHM_SIZE;
    mode = S_IRWXU|S_IRWXG;
    /* Open the shared memory object */
    if ( (shmdes = shm_open(shm_fn,O_CREAT|O_RDWR|O_TRUNC, mode)) == -1 )
    {
        perror("shm_open failure");
        exit(1);
    }
    /* Preallocate a shared memory area */
    SHM_SIZE = sysconf(_SC_PAGE_SIZE);
    if(ftruncate(shmdes, SHM_SIZE) == -1)
    {
        perror("ftruncate failure");
        exit(1);
    }
    if((shmptr = mmap(0, SHM_SIZE, PROT_WRITE|PROT_READ, MAP_SHARED,
                      shmdes,0)) == (caddr_t) -1)
    {
        perror("mmap failure");
        exit(1);
    }
    /* Create a semaphore in locked state */
    sem_des = sem_open(sem_fn, O_CREAT, 0666, 1);
    if(sem_des == (void*)-1)
    {
        perror("sem_open failure");
        exit(1);
    }
    /* Access to the shared memory area */
    for(index = 0; index < 100; index++)
    {
        sem_wait(sem_des);
        printf("write %d into the shared memory shmptr[%d]\n", index, index);
        shmptr[index]=index;
        sleep(1);
        sem_post(sem_des);

    }
    /* Release the semaphore lock */

    munmap(shmptr, SHM_SIZE);
    /* Close the shared memory object */
    close(shmdes);
    /* Close the Semaphore */
    sem_close(sem_des);
    /* Delete the shared memory object */
    shm_unlink(shm_fn);
    return 0;
}
