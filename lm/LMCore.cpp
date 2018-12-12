#include "LMCore.h"
#include "LMUtils.h"
LMCore::LMCore()
{
    _ips = LMUtils::getLocalIpAddr();
}

void LMCore::add_user(uint32_t ip, string name)
{
    LMOther* other = this->_others[ip];
    if(other)
    {
        other->_name = name;
    }
    else
    {
        other = new LMOther;
        other->_ip = ip;
        other->_name = name;
        this->_others.insert(std::pair<uint32_t,LMOther*>(ip,other));
    }
}

