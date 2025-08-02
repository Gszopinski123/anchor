#include "rrpc.hpp"


#include <iostream>

void hello_world(rrpc::RrpcArgument arg) {
    std::cout << "Function: hello_world was called!" << std::endl;
}

int main(int argc, char** argv) {
    rrpc::RrpcClient client("127.0.0.1", 8080);
    client.bind(&hello_world, "hello_world");
    client.run();
    return 0;
}