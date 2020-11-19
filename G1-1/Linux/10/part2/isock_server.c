/*
 * isock_server : listen on an internet socket ; fork ;
 *                child does lookup ; replies down same socket
 * argv[1] is the name of the local datafile
 * PORT is defined in dict.h
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include "dict.h"

int main(int argc, char **argv) {
	struct sockaddr_in server;
	struct sockaddr_in clienta;
	int serversockfd,comm,n;
	Dictrec tryit;

	if (argc != 2) {
		fprintf(stderr,"Usage : %s <datafile>\n",argv[0]);
		exit(1);
	}
	serversockfd=socket(AF_INET,SOCK_STREAM,0);
	if(serversockfd==-1){
        perror("socket");
        exit(1);
	}

    memset(&server,'\0',sizeof(server));
    server.sin_family=PF_INET;
    server.sin_addr.s_addr=INADDR_ANY;//htonl(INADDR_ANY)
    server.sin_port=htons(8700);
    if(bind(serversockfd,(struct sockaddr *)&server,sizeof(server))==-1){
        perror("bind");
        exit(1);
    }
    if(listen(serversockfd,5)==-1){
        perror("listen");
    }
	/* Create the socket.
	 * Fill in code. */

	/* Initialize address.
	 * Fill in code. */

	/* Name and activate the socket.
	 * Fill in code. */

	/* main loop : accept connection; fork a child to have dialogue */
	int addlen_client=sizeof(clienta);
	for (;;) {
        comm=accept(serversockfd,(struct sockaddr *)&clienta,&addlen_client);
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
