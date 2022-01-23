#!/bin/bash

HOST_IP=192.168.88.252

sudo mkdir $PGFILES/coord1

sudo chown -R postgres:postgres $PGFILES/coord1

initdb -D $PGFILES/coord1 --nodename co1

sudo -u postgres echo "host all  all    0.0.0.0/0  trust" >> $PGFILES/coord1/pg_hba.conf
sudo -u postgres echo "listen_addresses='*'" >> $PGFILES/coord1/postgresql.conf
sudo -u postgres sed -i "s/^#gtm_host =.*/gtm_host = 'gtm'/" $PGFILES/coord1/postgresql.conf


postgres --coordinator -D $PGFILES/coord1/ -i >$LOG_DIR/logfile_Px_c 2>&1  &


sleep 5
psql -U postgres -f '/home/postgres/entrypoint.sql'

tail -f $LOG_DIR/logfile_Px_c

