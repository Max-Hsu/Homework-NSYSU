/*
 * usock_server : listen on a Unix socket ; fork ;
 *                child does lookup ; replies down same socket
 * argv[1] is the name of the local datafile
 * PORT is defined in dict.h
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include "dict.h"

int main(int argc, char **argv)
{
    struct sockaddr_un server;
    struct sockaddr_un clienta;
    int fdof,n;
    int comm;
    Dictrec tryit;

    if (argc != 3)
    {
        fprintf(stderr,"Usage : %s <dictionary source>"
                "<Socket name>\n",argv[0]);
        exit(errno);
    }

    if((fdof=socket(AF_UNIX,SOCK_STREAM,0))==-1)
    {
        perror("socket");
        exit(1);
    }
    /*
    char *a;
    a=(char *)malloc(1000*sizeof(char));
    getcwd(a,1000);
    strcat(a,"/");
    strcat(a,argv[2]);
    */
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path,argv[2]);
    //printf("%s\n",a);
    unlink(server.sun_path);
    int sizeaaa=sizeof(struct sockaddr_un);
    if(bind(fdof,(struct sockaddr *)&server,sizeaaa)==-1)
    {
        perror("bind error");
        exit(1);
    }



    /* Setup socket.
     * Fill in code. */

    /* Initialize address.
     * Fill in code. */

    /* Name and activate the socket.
     * Fill in code. */

    /* main loop : accept connection; fork a child to have dialogue */
    if(listen(fdof,20)==-1)
    {
        perror("listen");
    }
    int sizeaa=sizeof(struct sockaddr_un);
    for (;;)
    {

        comm=accept(fdof,(struct sockaddr *)&clienta,&sizeaa);
        //printf("hello\n");
        if(comm==-1)
        {
            perror("accept");
            exit(1);
        }
        /* Wait for a connection.
         * Fill in code. */

        /* Handle new client in a subprocess. */
        int dtat;
        switch (fork())
        {
        case -1 :
            DIE("fork");
        case 0 :
            //close (sd);	/* Rendezvous socket is for parent only. */
            /* Get next request.
             * Fill in code. */

            while (dtat=read(comm,&tryit,sizeof(tryit)))  //????
            {

                //dtat=read(comm,&tryit,sizeof(tryit));
                if(dtat==-1)
                {
                    perror("read");
                    exit(1);
                }
                //printf("%d  %s %s\n",dtat,tryit.word,tryit.text);
                /* Lookup request. */
                switch(lookup(&tryit,argv[1]) )
                {
                /* Write response back to client. */
                case FOUND:
                    /* Fill in code. */
                    write(comm,&tryit,sizeof(tryit));
                    break;
                case NOTFOUND:
                    /* Fill in code. */
                    strcpy(tryit.text,"xxxx");
                    write(comm,&tryit,sizeof(tryit));
                    break;
                case UNAVAIL:
                    DIE(argv[1]);
                } /* end lookup switch */
                //close(comm);


            } /* end of client dialog */

            /* Terminate child process.  It is done. */
            exit(0);

        /* Parent continues here. */
        default :
            break;
        } /* end fork switch */
    } /* end forever loop */
} /* end main */
