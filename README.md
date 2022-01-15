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

Setup client/hub aplication:

- ./miniDBHub <NODE1_IP> <NODE1_PORT> <NODE2_IP> <NODE2_PORT> ... <NODEn_IP> <NODEn_PORT>


---------------------------------------------------


FORMATTER:
--


STATIC ANALYSIS:

-- clang-tidy etc..


RUN-TIME ANALYSIS:

-- sanitizers etc..

REVERSE ENGINEERING:

....
