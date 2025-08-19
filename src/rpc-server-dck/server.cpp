#include <iostream>

#include "rrpc.hpp"

int main(int argc, char** argv) {
    rrpc::RrpcServer srv(8080);
    srv.connect();
    while (true) {
        
    }
    return 0;
}