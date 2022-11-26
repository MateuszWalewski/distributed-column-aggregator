1. Dependencies

- Loki by Andrei Alexandrescu (https://loki-lib.sourceforge.net/)
- rpclib (https://github.com/rpclib/rpclib)
- boost
- clang++ 10

2. Running the application

Build the docker image from the project repo:

- docker build -t minidb_1.0 -f docker_setup_example/Dockerfile .

Setup the app in docker containers

- docker-compose -f 1_hub_2_nodes.yml up -d

Kick-off the interperter

- docker exec -it hub bash -c "python3.8 -i engine/initDB.py"

Enable view from nodes in the separate windows:

- docker logs -f node1
- docker logs -f node2

Run into simple example:

a = DoubleColumn()
a.LoadData("data3.csv")
a.Print()
print(a.Sum())
a = None

data3.csv resides ./data directory

------------------------------------------------

---------- RUNNING BENCHMARKS ------------------

- docker exec -it hub bash -c "pytest" ( with app deployed in above steps )

OR just use convenient script cleaning & starting containers from the scratch:

- ./run_benchmarks.sh

------------------------------------------------


4. Running the application (olad way)

Building the project

- in /build folder execute:
`cmake ..`
and then:
`make`


Setup nodes first by executing:

- ./node <NODE1_IP> <NODE1_PORT>
.
.
- ./node <NODEn_IP> <NODEn_PORT>

for n nodes.

One can launch many nodes with the same or differrent IPs

Setup hub aplication using python interpreter:

- move the "initDB.py" when the interpreter.so ( shared library compiled from hub.cpp )
is located
- run "python -i initDB.py"


5. Running Unit Tests

- docker exec -it hub bash -c "cd engine/build/ && ctest -V"

or just with script: ./run_ctest.sh

6. Static analysis:
For ex.
- clang-tidy -p ./src/ ./src/ParameterController/ParameterControllerHub.cpp -checks=* -header-filter=.* --

---------------------------------------------------


FORMATTER:
------------------
Edit configuration:
vim .clang-format

Run:
./formatter

STATIC ANALYSIS:
------------------
-- clang-tidy etc..


RUN-TIME ANALYSIS:

-- sanitizers etc..

REVERSE ENGINEERING:

....
