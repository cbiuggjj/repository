#ifndef LMNETWORK_H
#define LMNETWORK_H

#include "LMCore.h"

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
};

#endif // LMNETWORK_H
