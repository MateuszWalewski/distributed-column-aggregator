#!/bin/bash

docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_1_node.yml down -t0
docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_1_node.yml up -d

docker exec -it hub bash -c "pytest"
docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_1_node.yml down -t0
