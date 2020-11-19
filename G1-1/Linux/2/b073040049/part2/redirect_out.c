/*
 * redirect_out.c   :   check for >
 */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "shell.h"
#include <string.h>
#define STD_OUTPUT 1
#define STD_INPUT  0

/*
 * Look for ">" in myArgv, then redirect output to the file.
 * Returns 0 on success, sets errno and returns -1 on error.
 */
int redirect_out(char ** myArgv)
{
    int i = 0;
    int fd[2];
    int flag=0;
    while (myArgv[i]!=NULL)
    {
        if(strcmp(myArgv[i],">")==0)
        {
            flag=1;
            break;
        }
        i++;
    }
    /* search forward for >
     * Fill in code. */
    if(flag==1)
    {
        if (strcmp(myArgv[i],">")==0)  	/* found ">" in vector. */
        {
            char **cut;
            //int max=sizeof(*myArgv[0]);
            cut=(char**)malloc(sizeof(char)*i);
            for(int w=0; w<i; w++)
            {
                //max=sizeof(*myArgv[w]);
                //cut=(char**)realloc(cut,max*(w+1));
                cut[w]=myArgv[w];
            }
            /* 1) Open file.
             * 2) Redirect to use it for output.
             * 3) Cleanup / close unneeded file descriptors.
             * 4) Remove the ">" and the filename from myArgv.
             *
             * Fill in code. */
            //fd=open(myArgv[i-1],O_RDONLY);
            FILE *fd_a;
            fd_a=fopen(myArgv[i+1],"a+");
            /*if(fd==-1){
                perror("open error");
            }*/
            if(fd_a==NULL)
            {
                perror("open error");
            }
            char buff[1000];
            //int b_read;
            pipe(fd);
            pid_t pid;
            pid=fork();
            switch(pid)
            {
            case -1:
                perror("fork");
                exit(errno);
            default:
                close(1);
                dup2(fd[1],1);
                close(fd[0]);
                execvp(cut[0],cut);
            case 0:
                close(0);
                dup2(fd[0],0);
                close(fd[1]);
                if(read(fd[0],buff,1000)>0)
                {
                    fprintf(fd_a,"%s",buff);
                }
            }
            fclose(fd_a);
        }




    }
    return flag;
}

