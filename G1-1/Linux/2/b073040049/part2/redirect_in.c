/*
 * redirect_in.c  :  check for <
 */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "shell.h"
#define STD_OUTPUT 1
#define STD_INPUT  0

/*
 * Look for "<" in myArgv, then redirect input to the file.
 * Returns 0 on success, sets errno and returns -1 on error.
 */
int redirect_in(char ** myArgv)
{
    int i = 0;
    int fd[2];
    int flag=0;
    while(myArgv[i]!=NULL)
    {
        printf("%d  %s",i,myArgv[i]);
        if(myArgv[i][0]=='<')
        {
            flag=1;
            printf("true");
            break;
        }
        i++;

    }
    /* search forward for <
     *
     * Fill in code. */
    if(flag==1)
    {
        printf("flag up");
        if (myArgv[i][0]=='<')  	// found "<" in vector.
        {
            printf("now");
            char **cut;
            cut=(char **)malloc(100000);
            for(int w=0; w<i; w++)
            {

                cut[w]=myArgv[w];
                printf("  %s  ",cut[w]);
            }

            /* 1) Open file.
             * 2) Redirect stdin to use file for input.
             * 3) Cleanup / close unneeded file descriptors.
             * 4) Remove the "<" and the filename from myArgv.
             *
             * Fill in code. */
            FILE *fd_i;
            fd_i=fopen(myArgv[i+1],"r");
            if(fd_i==NULL)
            {
                perror("open error");
            }
            char buff[1000000];
            char buff_i[1000000];
            pipe(fd);
            pid_t pid;
            pid=fork();
            switch(pid)
            {
            case -1:
                perror("fork error");
            default:
                close(0);
                dup2(fd[0],0);
                close(fd[1]);
                if(read(fd[0],buff_i,1000000)>0)
                {
                    execvp(cut[0],cut);
                    printf("%s  ",buff_i);
                }
                wait(0);
                return 0;
            case 0:
                close(1);
                dup2(fd[1],1);
                close(fd[0]);
                while((fscanf(fd_i,"%s",buff))!=EOF)
                {
                    //printf("  %s  ",buff);
                    int len=strlen(buff);
                    write(fd[1],buff,len);
                }


            }
        }

    }
    return flag;
}
