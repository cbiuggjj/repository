#include "LMUserInput.h"
#include "LMNetwork.h"
#include "LMJson.h"
#include "LMUtils.h"

int main(int argc,char* argv[])
{
    LMUserInput input;
    LMNetwork* network = LMNetwork::instance();

    LMJson json;
    json.add(LM_CMD,LM_ONLINE);
    json.add(LM_NAME,LMUtils::getHostName());
    network->send(json.print());
    while(1)
    {
        input.loop();
    }

    return 0;
}
