1. Dependencies

- clang++ 10 
- rpclib (https://github.com/rpclib/rpclib)

2. Building project

- in /build folder execute: 
`cmake ..`
and then:
`make`


3. Running the application

Setup nodes first by executing:

- ./miniDBNode <NODE1_IP> <NODE1_PORT>
.
.
- ./miniDBNode <NODEn_IP> <NODEn_PORT>

for n nodes.

One can launch many nodes with the same or differrent IPs

Setup hub aplication using python interpreter:

- move the "initDB.py" when the interpreter.so ( shared library compiled from miniDBHub.cpp )
is located
- run "python -i initDB.py"



4. Static analysis:
For ex.
- clang-tidy -p ./src/ ./src/ParameterController/ParameterControllerHub.cpp -checks=* -header-filter=.* --

---------------------------------------------------


FORMATTER:
--


STATIC ANALYSIS:

-- clang-tidy etc..


RUN-TIME ANALYSIS:

-- sanitizers etc..

REVERSE ENGINEERING:

....