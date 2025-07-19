#include "rpc/client.h"


#include <iostream>


int main(int argc, char** argv) {
    std::cout << "client attempting to start" << std::endl;
    rpc::client client("127.0.0.1", 8080);
    client.call("printPlease");
    std::cout << "I think something is happening!" << std::endl;
    return 0;
}