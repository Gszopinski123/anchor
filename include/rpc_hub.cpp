
#include "rpc_hub.hpp"


kafkahub::KafkaHub::KafkaHub(std::string hostname, int port, std::string topic) {
    this->port = port;
    this->hostname = hostname;
    this->hostname.append(":");
    this->hostname.append(std::to_string(this->port));
    this->topic_name = topic;
    std::cout << "Topic is: " << this->topic_name << ", hostname is: " << this->hostname << std::endl;
    this->conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    if (this->conf->set("bootstrap.servers",this->hostname,this->errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << "Config error: " << this->errstr << std::endl;
        exit(EXIT_FAILURE);
    }

    this->consumer = RdKafka::Consumer::create(this->conf,this->errstr);
    if (!this->consumer) {
        std::cerr << "Consumer Creation Failure: " << this->errstr << std::endl;
        exit(EXIT_FAILURE);
    }
    delete this->conf;
    this->topic = RdKafka::Topic::create(consumer, topic_name, nullptr, errstr);
    if (!this->topic) {
        std::cerr << "Failed to create topic object: " << errstr << std::endl;
        exit(EXIT_FAILURE);
    }
}
