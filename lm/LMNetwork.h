#ifndef LMNETWORK_H
#define LMNETWORK_H

#include "LMCore.h"
#include "LMJson.h"

using namespace std;
class LMNetwork
{
public:
    static LMNetwork* instance();
    pthread_t _tid;
    int _udpfd;
    char _buf[4096];

    static void* thread_func(void* ptr);
    void* _thread_func(void* ptr);
    //send all
    void send(string msg,uint32_t ip=0xffffffff);
private:
    LMNetwork();
    void handle_online(LMJson& json,uint32_t peerip);
    void handle_online_ack(LMJson &json,uint32_t peerip);
    void handle_send_msg(LMJson& json);
    void hadnle_send_file(LMJson &json,uint32_t peerip);
};

#endif // LMNETWORK_H
