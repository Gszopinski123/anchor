
#include "rpc_hub.hpp"


rpchub::RpcHub::RpcHub(int port) {
    this->port = port;
    this->socket_fd = socket(AF_INET, SOCK_STREAM, NO_FLAGS);
}