#ifndef RPC_HUB_H_

#define RPC_HUB_H_
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <librdkafka/rdkafkacpp.h>
#include <unistd.h>
namespace kafkahub {
    class KafkaHub {
        public:
            KafkaHub(std::string hostname, int port, std::string topic);
        private:
            std::string hostname;
            std::string topic_name;
            std::string errstr;
            RdKafka::Conf* conf;
            RdKafka::Consumer* consumer;
            RdKafka::Topic* topic;
            int port;
    };
};

#endif