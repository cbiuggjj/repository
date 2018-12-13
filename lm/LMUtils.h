#ifndef LMUTILS_H
#define LMUTILS_H
#include "LMCore.h"
#include "LM.h"
class LMUtils
{
public:
    LMUtils();

    static char* getHostName();

    static list<uint32_t> getLocalIpAddr();
    static string ipaddr(uint32_t ip);
    static bool isBroadcast(string ip);
};

#endif // LMUTILS_H
