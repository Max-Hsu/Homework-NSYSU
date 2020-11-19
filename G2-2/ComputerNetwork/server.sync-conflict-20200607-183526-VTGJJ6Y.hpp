#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

struct Bind{
    //uint32_t ServerIp;
    //uint16_t ServerPort;
    uint32_t ClientIp;
    uint16_t ClientPort;
    uint32_t Last_Sequence;
    uint32_t Packet_Size;
};


/* 
struct SendingInfoToPthread{
    pthread_cond_t      cond_signal;
    char *              ReceivingBUF_PTH;
    struct TcpHEADER *  Header;

}; */