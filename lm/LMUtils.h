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
};

#endif // LMUTILS_H
