#!/bin/bash
set -e

NODE_ID=$(hostname | awk -F'-' '{print $NF}')
NUM_OF_ZK_NODES=3
STR_ZK_HOSTS="zk-kafka-sset-0.zk-kafka-svc.default.svc.cluster.local:2181"

mkdir -p kafka-logs
touch server.properties

echo "broker.id=$NODE_ID" >> server.properties
echo "log.dirs=/kafka-logs" >> server.properties

for ((i=1; i<=$NUM_OF_ZK_NODES; i++)); do
    STR_ZK_HOSTS="$STR_ZK_HOSTS,zk-kafka-sset-$i.zk-kafka-svc.default.svc.cluster.local:2181"
done

echo "zookeeper.connect=$STR_ZK_HOSTS" >> server.properties
echo "listeners=PLAINTEXT://:9092" >> server.properties
echo "advertised.listeners=PLAINTEXT://${HOSTNAME}.kafka-svc.default.svc.cluster.local:9092" >> server.properties
cat kafka.cfg >> server.properties
./kafka_2.13-3.9.1/bin/kafka-server-start.sh server.properties