#!/bin/bash

docker-compose -f ./docker_setup_example/1_hub_1_node.yml down -t0
docker-compose -f ./docker_setup_example/1_hub_1_node.yml up -d

docker exec -it hub bash -c "pytest"
docker-compose -f ./docker_setup_example/1_hub_1_node.yml down -t0
