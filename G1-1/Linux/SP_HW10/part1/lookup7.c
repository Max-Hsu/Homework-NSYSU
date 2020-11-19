/*
 * lookup7 : does no looking up locally, but instead asks
 * a server for the answer. Communication is by Unix TCP Sockets
 * The name of the socket is passed as resource.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "dict.h"

int lookup(Dictrec * sought, const char * resource)
{
    static int sockfd;
    static struct sockaddr_un server;
    static int first_time = 1;
    int n;

    if (first_time)       /* connect to socket ; resource is socket name */
    {
        first_time = 0;
        if((sockfd=socket(AF_UNIX,SOCK_STREAM,0))==-1)
        {
            perror("socket");
            exit(1);
        }
        /* Set up destination address.
         * Fill in code. */

        /* Allocate socket. */

        server.sun_family = AF_UNIX;
        strcpy(server.sun_path,resource);
        if(connect(sockfd,(struct sockaddr * )&server,sizeof(server))==-1)
        {
            perror("connect");
            exit(1);
        }
        /*

        unlink(server.sun_path);
        if(bind(sockfd,(struct sockaddr *)&server),sizeof(name)==-1){
            perror("bind error");
            exit(1);
        }
        */

        /* Connect to the server.
         * Fill in code. */
    }
    Dictrec finding;
    write(sockfd,&sought,sizeof(sought));
    read(sockfd,&finding,sizeof(finding));
    close(sockfd);
    /* write query on socket ; await reply
     * Fill in code. */

    if (strcmp(finding->text,"XXXX") != 0)
    {
        return FOUND;
    }

    return NOTFOUND;
}
