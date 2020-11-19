/*
 * lookup9 : does no looking up locally, but instead asks
 * a server for the answer. Communication is by Internet UDP Sockets
 * The name of the server is passed as resource. PORT is defined in dict.h
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#include "dict.h"

int lookup(Dictrec * sought, const char * resource) {
    int sockfd;
    static struct sockaddr_in server;
    struct sockaddr_in clienta;
    struct in_addr ** addr_list;
    struct hostent *host;
    static int first_time = 1;

    if (first_time)          /* connect to socket ; resource is server name */
    {
        first_time = 0;

        sockfd=socket(AF_INET, SOCK_DGRAM, 0);
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

        //server.sin_addr.s_addr=htonl(INADDR_ANY);

        memcpy((char *)&server.sin_addr,host->h_addr,host->h_length);
        /* Fill in code. */


        /*
        if(bind(sockfd,(struct sockaddr *)&server,sizeof(server))==-1){
            perror("bind");
            exit(1);
        }
        */


        /* Allocate socket.
         * Fill in code. */

        /* Connect to the server.
         * Fill in code. */
    }
    int size_server;
    size_server=sizeof(server);
    Dictrec finding;
    sendto(sockfd,sought,WORD+TEXT,0,(struct sockaddr*)&server,sizeof(server));

    recvfrom(sockfd,&finding,WORD+TEXT,0,(struct sockaddr*)&server,&size_server);


    /* write query on socket ; await reply
     * Fill in code. */

    if (strcmp(finding.text,"xxxx") != 0)
    {
        strcpy(sought->text,finding.text);
        return FOUND;
    }

	return NOTFOUND;
}
