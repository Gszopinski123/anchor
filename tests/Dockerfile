FROM ubuntu:latest
COPY ../../config/kafka.cfg .
COPY ../../scripts/kafka-entrypoint.sh .
RUN apt-get update
RUN apt-get install -y wget openjdk-11-jdk tar net-tools 
RUN wget https://downloads.apache.org/kafka/3.9.1/kafka_2.13-3.9.1.tgz
RUN tar -xvf kafka_2.13-3.9.1.tgz
RUN rm -rf kafka_2.13-3.9.1.tgz
CMD ["sleep", "50000"]