FROM ubuntu:20.04

RUN apt-get update

# Setup for flex bison

ENV TZ=Europe
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Installing dependencies ... 

RUN apt-get install -y build-essential libreadline-dev zlib1g-dev flex bison \ 
wget curl git dnsutils vim sudo libssl-dev cmake software-properties-common  \
libboost-all-dev python3 python3-dev


# Setting the user

RUN useradd -ms /bin/bash guest1
USER guest1
WORKDIR /home/guest1


# Tasks requiring root permissions.
USER root

RUN git clone https://github.com/rpclib/rpclib.git
RUN cd rpclib && mkdir build && cd build && cmake .. -DCMAKE_CXX_FLAGS="-fpic" && make -j2 && make install

ADD engine /home/guest1/engine
RUN chown -R guest1:guest1 engine
RUN cd engine && mkdir build && cd build && cmake .. && make -j2 && make install
ADD docker_setup_example/setup_scripts /home/guest1/setup_scripts



