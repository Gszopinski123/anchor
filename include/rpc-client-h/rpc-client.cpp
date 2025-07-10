

#include "rpc-client.hpp"


rpc_client::RpcClientServer::RpcClientServer(int port) {
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == 0) {
        perror("Socket failure");
        exit(EXIT_FAILURE);
    } 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(socketfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failure");
        exit(EXIT_FAILURE);
    }
    if (listen(socketfd, 3) < 0) {
        perror("Listen failure");
        exit(EXIT_FAILURE);
    }
}

void rpc_client::RpcClientServer::run() {
    int incoming_fd = accept(socketfd,(struct sockaddr*)&incoming_addr,&incoming_addr_size);
    if (incoming_fd < 0) {
        perror("Accept Failure");
        exit(EXIT_FAILURE);
    }
    //continously read here

    close(incoming_fd);
}

rpc_client::RpcClientServer::~RpcClientServer() {
    close(socketfd);
}