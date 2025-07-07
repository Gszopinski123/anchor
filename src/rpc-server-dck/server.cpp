#include <iostream>
#include "rpc/server.h"

void printPlease(void) {
    std::cout << "it worked!" << std::endl;
}

int main(int argc, char** argv) {

    rpc::server srv(8080);
    srv.bind("printPlease",&printPlease);

    srv.run();
    return 0;
}