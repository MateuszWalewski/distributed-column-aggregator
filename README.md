## JUST A PROOF OF CONCEPT. NEEDS TO BE REFACTORIZED ##

### Dependencies

- Loki by Andrei Alexandrescu: https://loki-lib.sourceforge.net/
- rpclib by Tamás Szelei: https://github.com/rpclib/rpclib
- boost-1.71.0
- clang++ 10
- pytest
- docker

### Running the application

#### Build the docker image from the project repo:

```docker build . -t minidb_1.0```

#### Setup the app in docker containers

```docker compose -f ./docker_setup/1_hub_2_nodes.yml up -d```

#### Kick-off the interperter

```docker exec -it hub bash -c "python3 -i engine/initDB.py"```

#### Enable view from nodes in the separate terminal windows:

```
docker logs -f node1
docker logs -f node2
```
## Usage:
```
a = DoubleColumn() 
a.LoadData("data4.csv")
a.Print()
result = a.Sum()
result = a.Count()
result = a.MomentI()
result = a.MomentII()
result = a.Stddev()
```

### Benchmarks

```docker exec -it hub bash -c "pytest" ```

Or just use convenient script starting containers from scratch:

```scripts/run_benchmarks_2_nodes.sh```

#### Running Unit Tests

``` docker exec -it hub bash -c "cd engine/build/ && ctest -V"```

or just with script: 

```scripts/run_ctest.sh```

#### Static analysis:
```
clang-tidy -p ./src/ ./src/ParameterController/ParameterControllerHub.cpp -checks=* -header-filter=.* --
```

#### Formatter:
Just run:
```./formatter```

To edit configuration:
```vim .clang-format```