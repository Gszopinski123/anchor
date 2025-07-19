#include <iostream>
#include "rpc/server.h"

void printPlease(void) {
    std::cout << "it worked!" << std::endl;
}

int main(int argc, char** argv) {
    int port = 8080;
    rpc::server srv(port);
    srv.bind("printPlease",&printPlease);

    srv.run();
    return 0;
}