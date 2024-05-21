#!/bin/bash

docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_2_nodes.yml down -t0
docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_2_nodes.yml up -d

docker exec -it hub bash -c "pytest"
docker compose -f $HOME/distributed-column-aggregator/docker_setup/1_hub_2_nodes.yml down -t0
