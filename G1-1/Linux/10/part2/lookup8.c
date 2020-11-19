/*
 * lookup8 : does no looking up locally, but instead asks
 * a server for the answer. Communication is by Internet TCP Sockets
 * The name of the server is passed as resource. PORT is defined in dict.h
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "dict.h"

int lookup(Dictrec * sought, const char * resource)
{
    int sockfd;
    static struct sockaddr_in server;
    struct in_addr ** addr_list;
    struct hostent *host;
    static int first_time = 1;

    if (first_time)          /* connect to socket ; resource is server name */
    {
        first_time = 0;

        sockfd=socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1)
        {
            perror("socket");
            exit(1);
        }
        host=gethostbyname(resource);
        if(host==NULL)
        {
            herror("gethost");
        }
        addr_list = (struct in_addr **)host->h_addr_list;
        //printf("get: %s\n",inet_ntoa(*addr_list[0]));
        /* Set up destination address. */
        memset(&server,'\0',sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port=htons(8700);
        memcpy((char *)&server.sin_addr,host->h_addr,host->h_length);
        /* Fill in code. */
        if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))==-1){
            perror("connect");
            exit(1);
        }
        /* Allocate socket.
         * Fill in code. */

        /* Connect to the server.
         * Fill in code. */
    }
    Dictrec finding;
    write(sockfd,sought,sizeof(Dictrec));
    read(sockfd,&finding,sizeof(Dictrec));

    /* write query on socket ; await reply
     * Fill in code. */

    if (strcmp(finding.text,"xxxx") != 0)
    {
        strcpy(sought->text,finding.text);
        return FOUND;
    }

    return NOTFOUND;
}
