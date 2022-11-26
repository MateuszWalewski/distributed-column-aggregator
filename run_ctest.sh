#!/bin/bash

docker-compose -f ./docker_setup_example/1_hub.yml down -t0
docker-compose -f ./docker_setup_example/1_hub.yml up -d

docker exec -it hub bash -c "cd engine/build/ && ctest -V"
docker-compose -f ./docker_setup_example/1_hub.yml down -t0
