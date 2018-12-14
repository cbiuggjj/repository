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
#include <vector>
#include <sys/stat.h>
#include <dirent.h>
#include <strings.h>

#define LM_PORT_UDP 9999
#define LM_PORT_TCP 9998
#define LM_CMD "cmd"
#define LM_ONLINE "online"
#define LM_NAME "name"
#define LM_ONLINEACK "onlineack"
#define LM_LIST "list"
#define LM_SEND "send"
#define LM_SENDF "sendf"
#define LM_CONTENT "content"
#define LM_SENDA "senda"
#define LM_PATH "path"
#define LM_FILE_TYPE_REG 0
#define LM_FILE_TYPE_DIR 1
#define LM_FILE_TYPE_LINK 2
#define LM_FILE_TYPE_OTHER 3
#define LM_REG "r"
#define LM_DIR "d"
#define LM_SPERATOR "5h5h"
#define LM_FILEOFF "0"
