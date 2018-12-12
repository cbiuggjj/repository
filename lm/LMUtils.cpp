#include "LMUtils.h"

LMUtils::LMUtils()
{

}

char *LMUtils::getHostName()
{
    static char hostName[128]={0};
    if(strlen(hostName)!=0)
        return hostName;
    FILE* fp = fopen("/etc/hostname","r");
    fgets(hostName,sizeof(hostName),fp);
    hostName[strlen(hostName)-1]=0;
    fclose(fp);
    return hostName;
}

list<uint32_t> LMUtils::getLocalIpAddr()
{
    FILE* fp = popen("ifconfig | grep inet | grep -v inet6 | awk '{print $2}' | awk -F ':' '{print $2}'","r");
    list<uint32_t> ret;
    char buf[128];
    while(fgets(buf,sizeof(buf),fp))
    {
        buf[strlen(buf)-1]=0;
        uint32_t ip = inet_addr(buf);
        ret.push_back(ip);
    }
    pclose(fp);
    return ret;
}

string LMUtils::ipaddr(uint32_t ip)
{
    uint8_t* p = (uint8_t*)&ip;
    char buf[128];
    sprintf(buf,"%d,%d,%d,%d",p[3],p[2],p[1],p[0]);
    return string(buf);
}

