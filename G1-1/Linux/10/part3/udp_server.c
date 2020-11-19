/*
 * udp_server : listen on a UDP socket ;reply immediately
 * argv[1] is the name of the local datafile
 * PORT is defined in dict.h
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#include "dict.h"

int main(int argc, char **argv)
{
    static struct sockaddr_in server;
    int sockfd,size_server;
    Dictrec tryit;

    if (argc != 2)
    {
        fprintf(stderr,"Usage : %s <datafile>\n",argv[0]);
        exit(errno);
    }
    sockfd=socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd==-1)
    {
        perror("socket");
        exit(1);
    }
    memset(&server,'\0',sizeof(server));
    int addlen_server=sizeof(server);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;//htonl(INADDR_ANY)
    server.sin_port=htons(8700);
    if(bind(sockfd,(struct sockaddr *)&server,sizeof(server))==-1)
    {
        perror("bind");
        exit(1);
    }
    /* Create a UDP socket.
     * Fill in code. */

    /* Initialize address.
     * Fill in code. */

    /* Name and activate the socket.
     * Fill in code. */
    size_server=sizeof(server);
    int read_size;
    for (;;)   /* await client packet; respond immediately */
    {
        read_size=recvfrom(sockfd,&tryit,WORD+TEXT,0,(struct sockaddr * )&server,&size_server);

        /* siz must be non-zero */

        /* Wait for a request.
         * Fill in code. */

        while (read_size>0)
        {
            /* Lookup request and respond to user. */
            switch(lookup(&tryit,argv[1]))
            {
            case FOUND:
                /* Fill in code. */
                sendto(sockfd,&tryit,WORD+TEXT,0,(struct sockaddr*)&server,size_server);
                read_size=0;
                break;
            case NOTFOUND:
                /* Fill in code. */
                strcpy(tryit.text,"xxxx");
                sendto(sockfd,&tryit,WORD+TEXT,0,(struct sockaddr*)&server,size_server);
                read_size=0;
                break;
            case UNAVAIL:
                DIE(argv[1]);
            } /* end lookup switch */
        } /* end while */
    } /* end forever loop */
} /* end main */
