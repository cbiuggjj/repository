#ifndef LMUSERINPUT_H
#define LMUSERINPUT_H
#include "LMCore.h"

class LMUserInput
{
public:
    LMUserInput();
    char _buf[4096];
    void get();

};

#endif // LMUSERINPUT_H
