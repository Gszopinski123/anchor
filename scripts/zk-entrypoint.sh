#!/bin/bash
set -e

NODE_ID=$(echo ${HOSTNAME##*-})
echo $NODE_ID > /zookeeper/zookeeper-data/myid

./kafka_2.13-3.9.1/bin/zookeeper-server-start.sh ./kafka_2.13-3.9.1/config/zoo.cfg