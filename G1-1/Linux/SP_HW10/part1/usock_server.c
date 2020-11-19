/*
 * usock_server : listen on a Unix socket ; fork ;
 *                child does lookup ; replies down same socket
 * argv[1] is the name of the local datafile
 * PORT is defined in dict.h
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include "dict.h"

int main(int argc, char **argv)
{
    struct sockaddr_un server;
    int fd,n;
    Dictrec tryit;

    if (argc != 3)
    {
        fprintf(stderr,"Usage : %s <dictionary source>"
                "<Socket name>\n",argv[0]);
        exit(errno);
    }

    if((fd=socket(AF_UNIX,SOCK_STREAM,0))==-1){
        perror("socket");
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path,resource);
    unlink(server.sun_path);
    if(bind(fd,(struct sockaddr *)&server),sizeof(server)==-1)
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
    for (;;)
    {
        /* Wait for a connection.
         * Fill in code. */

        /* Handle new client in a subprocess. */
        switch (fork())
        {
        case -1 :
            DIE("fork");
        case 0 :
            //close (sd);	/* Rendezvous socket is for parent only. */
            /* Get next request.
             * Fill in code. */
            while ()

            {

                /* Lookup request. */
                switch(lookup(&tryit,argv[1]) )
                {
                /* Write response back to client. */
                case FOUND:
                    /* Fill in code. */
                    break;
                case NOTFOUND:
                    /* Fill in code. */
                    break;
                case UNAVAIL:
                    DIE(argv[1]);
                } /* end lookup switch */

            } /* end of client dialog */

            /* Terminate child process.  It is done. */
            exit(0);

        /* Parent continues here. */
        default :
                break;
            } /* end fork switch */
    } /* end forever loop */
} /* end main */
