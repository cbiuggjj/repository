#include <string>
#include <map>
#include <list>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdlib.h>
#include <algorithm>

#define LM_PORT_UDP 9999
#define LM_CMD "cmd"
#define LM_ONLINE "online"
#define LM_NAME "name"
#define LM_ONLINEACK "onlineack"
#define LM_LIST "list"
