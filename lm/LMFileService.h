#ifndef LMFILESERVICE_H
#define LMFILESERVICE_H
#include "LM.h"
#include "LMFileSend.h"
using namespace std;
class LMFileService
{
public:
    pid_t _pid;
    int _listenfd;
    static LMFileService* instance();
    void start();
    void sub_process_run();
    static void child_process_end(int sig);
    map<pid_t,LMFileSend*> _fileSendingProcess;
    static bool _bChildProcessEnd;
private:
    LMFileService();
};

#endif // LMFILESERVICE_H
