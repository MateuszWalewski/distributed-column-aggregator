FROM ubuntu:16.04


RUN apt-get update
RUN apt-get install -y build-essential libreadline-dev zlib1g-dev flex bison wget vim emacs24-nox curl git dnsutils vim sudo

RUN mkdir /postgres/log/ -p

# Set environment.
ENV VERSION 1.2.1
ENV INSTALL_DIR /opt/postgres-xc
ENV DATA_DIR /postgres
ENV LOG_DIR /postgres/log

# Install postgres-x2.
RUN cd /tmp && git clone https://github.com/postgres-x2/postgres-x2.git
RUN cd /tmp/postgres-x2 && git checkout REL1_2_STABLE
RUN cd /tmp/postgres-x2 && ./configure && make && make install


# Setup postgres user.
RUN adduser --disabled-password --gecos '' postgres
RUN adduser postgres sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
RUN chown -R postgres:postgres /postgres
RUN sed -i "s/^#\ rc.local.*/\/home\/postgres\/hosts.sh/" "/etc/rc.local"

ENV PATH /usr/local/pgsql/bin:$PATH
ENV PGFILES /usr/local/pgsql/bin

ADD setup_scripts/init_coordinator.sh /home/postgres/init_coordinator.sh
ADD setup_scripts/init_datanode.sh /home/postgres/init_datanode.sh
ADD setup_scripts/init_gtm.sh /home/postgres/init_gtm.sh

RUN chmod +x /home/postgres/*.sh

COPY setup_scripts/entrypoint.sql /home/postgres/entrypoint.sql
USER postgres

EXPOSE 5435 6666
