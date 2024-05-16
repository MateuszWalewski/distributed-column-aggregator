#!/bin/bash

docker compose -f $HOME/distributedDBPrototype/docker_setup/1_hub.yml down -t0
docker compose -f $HOME/distributedDBPrototype/docker_setup/1_hub.yml up -d

docker exec -it hub bash -c "cd engine/build/ && ctest -V"
docker compose -f $HOME/distributedDBPrototype/docker_setup/1_hub.yml down -t0
