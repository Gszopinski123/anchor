


#ifndef RPC_CLIENT_H_
#define RPC_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace rpc_client
{
    class RpcClientServer
    {
        int socketfd;
        int port;
        struct sockaddr_in address;
        struct sockaddr_in incoming_addr;
        socklen_t incoming_addr_size;
        public:
            RpcClientServer(int port);
            void run();
            ~RpcClientServer();
    };
}






#endif