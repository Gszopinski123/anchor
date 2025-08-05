#include <iostream>
#include <string>
#include <vector>
#include <librdkafka/rdkafkacpp.h>

int main() {
    std::string brokers = "localhost:9092";
    std::string topic_name = "test-topic";
    std::string errstr;

    // Configure the producer
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    if (conf->set("bootstrap.servers", brokers, errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << "Config error: " << errstr << std::endl;
        return 1;
    }

    // Create the producer
    RdKafka::Producer* producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Producer creation failed: " << errstr << std::endl;
        return 1;
    }
    delete conf;

    // Create topic object
    RdKafka::Topic* topic = RdKafka::Topic::create(producer, topic_name, nullptr, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic object: " << errstr << std::endl;
        return 1;
    }

    // Message to send
    std::string message = "Hello Kafka from C++!";
    std::vector<char> payload(message.begin(), message.end());

    // Produce message using correct overload
    RdKafka::ErrorCode resp = producer->produce(
        topic,                              // Topic*
        RdKafka::Topic::PARTITION_UA,       // Partition
        RdKafka::Producer::RK_MSG_COPY,     // Message flag
        payload.data(),                     // Payload pointer
        payload.size(),                     // Payload size
        nullptr,                            // Key (can be nullptr)
        nullptr                             // Message opaque
    );

    if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Produce failed: " << RdKafka::err2str(resp) << std::endl;
    } else {
        std::cout << "Message produced successfully!" << std::endl;
    }

    // Flush to make sure message is delivered
    producer->flush(5000);

    delete topic;
    delete producer;
    return 0;
}