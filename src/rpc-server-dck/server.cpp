#include <iostream>

#include "rrpc.hpp"
#include "rpc_hub.hpp"

int main(int argc, char** argv) {
    int option, numOfOptions;
    std::string hostname, topic;
    int port;
    int rpc_port = 8080;
    while((option = getopt(argc, argv,"h:H:p:P:t:T:")) != -1) {
        switch(option) {
            case 'h':
            case 'H':
                numOfOptions++;
                hostname = std::string(optarg);
            break;
            case 'p':
            case 'P':
                numOfOptions++;
                port = atoi(optarg);
            break;
            case 't':
            case 'T':
                numOfOptions++;
                topic = std::string(optarg);
            break;
            default:
                printf("INVALID OPTION\n"); 
                exit(EXIT_FAILURE);
            break;
        }
    }
    if (numOfOptions < 3) {
        printf("NOT ENOUGH OPTIONS\n");
        exit(EXIT_FAILURE);
    }

    kafkahub::KafkaHub hub(hostname,port,topic);


    rrpc::RrpcServer srv(rpc_port);
    srv.connect();
    while (true) {
        
    }
    return 0;
}