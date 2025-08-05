#ifndef RPC_HUB_H_

#define RPC_HUB_H_

#define NO_FLAGS 0
#include <stdlib.h>
#include <sys/socket.h>
namespace rpchub {
    
    class RpcHub {
        public:
            RpcHub(int port);
            ~RpcHub();
        private:
            int socket_fd;
            int port;
    };
};



#endif