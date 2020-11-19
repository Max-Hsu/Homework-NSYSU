typedef enum { FALSE, TRUE } Boolean;
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fifo_seqnum.h"
int serverFd;
int dummyFd;
struct request req;
void readout(int signo)
{
    close(dummyFd);
    for(;;){
        if (read(serverFd, &req, sizeof(struct request))!= sizeof(struct request)){
        break;
        }

    }
    close(serverFd);
    exit(0);
}
int main(int argc, char *argv[])
{

    struct sigaction act;
    act.sa_handler = readout;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGINT);
    sigaddset(&act.sa_mask,SIGTERM);
    act.sa_flags=0;
    sigaction(SIGINT,&act,NULL);
    sigaction(SIGTERM,&act,NULL);

    /*
    void (*old)(int);
    old=sigset(SIGINT,readout);
    old=sigset(SIGTERM,readout);
    */
    //int serverFd;
    int clientFd;
    char clientFifo[CLIENT_FIFO_NAME_LEN];
    //struct request req;
    struct response resp;
    int seqNum = 0;                     /* This is our "service" */

    /* Create well-known FIFO, and open it for reading */

    umask(0);                           /* So we get the permissions we want */
    if (mkfifo(SERVER_FIFO, S_IRUSR | S_IWUSR | S_IWGRP) == -1
            && errno != EEXIST)
        errExit("mkfifo %s", SERVER_FIFO);
    serverFd = open(SERVER_FIFO, O_RDONLY);
    if (serverFd == -1)
        errExit("open %s", SERVER_FIFO);

    /* Open an extra write descriptor, so that we never see EOF */

    dummyFd = open(SERVER_FIFO, O_WRONLY);
    if (dummyFd == -1)
        errExit("open %s", SERVER_FIFO);

    /* Let's find out about broken client pipe via failed write() */

    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        errExit("signal");

    for (;;)                            /* Read requests and send responses */
    {
        if (read(serverFd, &req, sizeof(struct request))!= sizeof(struct request))
        {
            fprintf(stderr, "Error reading request; discarding\n");
            continue;                   /* Either partial read or error */
        }

        /* Open client FIFO (previously created by client) */

        snprintf(clientFifo, CLIENT_FIFO_NAME_LEN, CLIENT_FIFO_TEMPLATE,
                 (long) req.pid);
        clientFd = open(clientFifo, O_WRONLY);
        if (clientFd == -1)             /* Open failed, give up on client */
        {
            errMsg("open %s", clientFifo);
            continue;
        }

        /* Send response and close FIFO */

        resp.seqNum = seqNum;
        if (write(clientFd, &resp, sizeof(struct response))
                != sizeof(struct response))
            fprintf(stderr, "Error writing to FIFO %s\n", clientFifo);
        if (close(clientFd) == -1)
            errMsg("close");

        seqNum += req.seqLen;           /* Update our sequence number */
    }
}
