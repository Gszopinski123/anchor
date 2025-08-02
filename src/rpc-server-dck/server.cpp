#include <iostream>

#include "rrpc.hpp"

int main(int argc, char** argv) {
    rrpc::RrpcServer srv(8080);
    srv.connect();
    rrpc::RrpcArgument arg;
    srv.send("hello_world",arg);
    return 0;
}