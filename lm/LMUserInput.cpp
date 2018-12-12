#include "LMUserInput.h"
#include "LMUtils.h"

LMUserInput::LMUserInput()
{



}

void LMUserInput::loop()
{
    getcmd();
    handlecmd();
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
    if(string(_buf) == LM_LIST)
    {
        handleList();
    }
    else //if(string(_buf) == )
    {

    }
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

