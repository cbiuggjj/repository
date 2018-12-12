#include "LMUserInput.h"
#include "LMUtils.h"
#include "LMNetwork.h"
#include "LMJson.h"

LMUserInput::LMUserInput()
{



}

void LMUserInput::loop()
{
    getcmd();
    splitCmd();
    handlecmd();
}

void LMUserInput::splitCmd()
{
    _args.clear();
    char* saveptr = NULL;
    char* first = strtok_r(this->_buf," \t",&saveptr);
    _args.push_back(first);
    char* second = strtok_r(NULL," \t",&saveptr);
    if(second)
    {
        _args.push_back(second);
    }
    else
        return;
    char* third = strtok_r(NULL," \0",&saveptr);
    if(third)
        _args.push_back(third);
    return;
}

void LMUserInput::getcmd()
{
    while(1)
    {
        fgets(_buf,sizeof(_buf),stdin);
        if(strlen(_buf)>1)
            break;
    }
    _buf[strlen(_buf)-1]=0;
}

void LMUserInput::handlecmd()
{
#define BRANCH(cmd,func) if(_args[0]==cmd) func()
    BRANCH(LM_LIST,handleList);
    BRANCH(LM_SEND,handleSend);
#if 0
    if(_args[0] == LM_LIST)
    {
        handleList();
    }
    else if(_args[1] == LM_SEND)
    {
        handleSend();
    }
#endif
}

void LMUserInput::handleList()
{
    printf("user list:\n");
    LMCore* core = LMCore::instance();
    for(auto it = core->_others.begin();it != core->_others.end(); it++)
    {
        LMOther* other = it->second;
        printf("%s(%s) \n",other->_name.c_str(),LMUtils::ipaddr(other->_ip).c_str());
    }

}

void LMUserInput::handleSend()
{
    if(_args.size()<3)
        return;
    string& ip = _args[1];
    string& content = _args[2];

    LMJson json;
    json.add(LM_CMD,LM_SEND);
    json.add(LM_NAME,LMCore::instance()->_name);
    json.add(LM_CONTENT,content);

    LMNetwork::instance()->send(json.print(),inet_addr(ip.c_str()));
}

