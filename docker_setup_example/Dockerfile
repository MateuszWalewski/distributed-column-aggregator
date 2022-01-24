FROM ubuntu:20.04


RUN apt-get update

ENV TZ=Europe
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get install -y build-essential libreadline-dev zlib1g-dev flex bison wget curl git dnsutils vim sudo libssl-dev

RUN wget https://github.com/Kitware/CMake/releases/download/v3.20.2/cmake-3.20.2.tar.gz
RUN tar -zxvf cmake-3.20.2.tar.gz 
RUN cd cmake-3.20.2 && ./bootstrap && make && sudo make install


# Set user

RUN useradd -ms /bin/bash guest1

USER guest1
WORKDIR /home/guest1

# Set environment.

# Dependecies installation.
USER root

RUN git clone https://github.com/rpclib/rpclib.git
RUN cd rpclib && mkdir build && cd build && cmake .. -DCMAKE_CXX_FLAGS="-fpic" && make -j2 && make install

# miniDB installation


# Setup scripts.


ADD engine /home/guest1/engine
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:deadsnakes/ppa && apt install -y python3.8 python3.8-dev
RUN apt-get install -y libboost-all-dev

RUN chown -R guest1:guest1 engine
RUN cd engine && mkdir build && cd build && cmake .. && make -j2 && make install
USER guest1


#COPY setup_scripts/entrypoint.sql /home/postgres/entrypoint.sql
ENTRYPOINT ["tail", "-f", "/dev/null"]

