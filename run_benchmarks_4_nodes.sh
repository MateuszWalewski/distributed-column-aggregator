#!/bin/bash

docker-compose -f ./docker_setup_example/1_hub_4_nodes.yml down -t0
docker-compose -f ./docker_setup_example/1_hub_4_nodes.yml up -d

docker exec -it hub bash -c "pytest"
docker-compose -f ./docker_setup_example/1_hub_4_nodes.yml down -t0
