#ifndef LMUSERINPUT_H
#define LMUSERINPUT_H
#include "LMCore.h"

class LMUserInput
{
public:
    LMUserInput();
    char _buf[4096];
    vector<string> _args;


    void loop();
    void splitCmd();
    void getcmd();
    void handlecmd();
    void handleList();
    void handleSend();
    void handleSendf();
    //void handleAll();

};

#endif // LMUSERINPUT_H
