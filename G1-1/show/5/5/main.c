#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
static int time=0;
int status=1;
int main()
{
    pid_t pida;
    printf("Hello world!\n");
    pida=fork();
    switch(pida)
    {
    case 0:
        while(status)
        {
            sleep(1);
            time++;
        }
        printf("%d",time);
        return 0;
    }
    scanf("%d",&status);
    waitpid(0,NULL,0);
    return 0;
}
