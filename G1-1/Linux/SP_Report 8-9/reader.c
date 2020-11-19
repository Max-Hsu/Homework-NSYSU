#include <sys/types.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char shm_fn[] = "my_shm";
char sem_fn[] = "my_sem";
/**** READER ****/
int main()
{
    caddr_t shmptr;
    int shmdes, index;
    sem_t *semdes;
    int SHM_SIZE;
    /* Open the shared memory object */
    SHM_SIZE = sysconf(_SC_PAGE_SIZE);
    if ( (shmdes = shm_open(shm_fn, O_RDWR, 0)) == -1 )
    {
        perror("shm_open failure");
        exit(1);
    }
    if((shmptr = mmap(0, SHM_SIZE, PROT_WRITE|PROT_READ, MAP_SHARED,
                      shmdes,0)) == (caddr_t) -1)
    {
        perror("mmap failure");
        exit(1);
    }
    /* Open the Semaphore */
    semdes = sem_open(sem_fn, 0, 0644, 1);
    if(semdes == (void*) -1)
    {
        perror("sem_open failure");
        exit(1);
    }
    /* Lock the semaphore */

        /* Access to the shared memory area */
        for(index = 0; index < 100; index++){
            sem_wait(semdes);
            printf("The shared memory shmptr[%d] = %d\n", index,shmptr[index]);
        /* Release the semaphore lock */
        sem_post(semdes);
        }

    munmap(shmptr, SHM_SIZE);
    /* Close the shared memory object */
    close(shmdes);
    /* Close the Semaphore */
    sem_close(semdes);
    sem_unlink(sem_fn);
    return 0;
}
