#include "LMNetwork.h"
#include "LMJson.h"

LMNetwork *LMNetwork::instance()
{
    static LMNetwork* theOne = NULL;
    if(theOne) return theOne;
    return theOne = new LMNetwork;
}

void *LMNetwork::thread_func(void *ptr)
{
    LMNetwork* This = instance();
    This->_thread_func(ptr);
}

void *LMNetwork::_thread_func(void *ptr)
{

    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    while(1)
    {
        memset(_buf,0,sizeof(_buf));
        recvfrom(_udpfd,_buf,sizeof(_buf),0,(struct sockaddr*)&addr,&len);
        list<uint32_t>& ips = LMCore::instance()->_ips;
        auto it = find(ips.begin(),ips.end(),addr.sin_addr.s_addr);
        if(it != ips.end())
        {
            continue;
        }
        LMJson json;
        if(!json.parse(_buf))
            continue;
        string cmd = json.get(LM_CMD);
        if(cmd == LM_ONLINE)
        {
            string name = json.get(LM_NAME);
            LMCore::instance()->add_user(addr.sin_addr.s_addr,name);
            //LMCore::instance()->_others.insert();
            LMJson resp;
            resp.add(LM_ONLINE,LM_ONLINEACK);
            resp.add(LM_NAME,LMCore::instance()->_name);
            printf("%s(ox%x) is online now \n",name.c_str(),addr.sin_addr.s_addr);
            //send(resp.print(),addr.sin_addr.s_addr);
        }
        else if(cmd == LM_ONLINEACK)
        {
            string name = json.get(LM_NAME);
            LMCore::instance()->add_user(addr.sin_addr.s_addr,name);
             printf("%s(ox%x) is online now \n",name.c_str(),addr.sin_addr.s_addr);
        }
    }
}

void LMNetwork::send(string msg,string ip)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(LM_PORT_UDP);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    sendto(this->_udpfd,msg.c_str(),strlen(msg.c_str()),0,(struct sockaddr*)&addr,sizeof(addr));
}

LMNetwork::LMNetwork()
{
    this->_udpfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(LM_PORT_UDP);
    addr.sin_addr.s_addr =INADDR_ANY;
    int ret = bind(_udpfd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        perror("bind");
        exit(1);
    }
    int opt = 1;
    setsockopt(_udpfd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));

    pthread_create(&_tid,NULL,thread_func,NULL);
}